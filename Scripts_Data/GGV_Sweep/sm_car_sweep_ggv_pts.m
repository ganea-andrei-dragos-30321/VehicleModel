function [simOut, simInput, filename_ggv] = sm_car_sweep_ggv_pts(baseModelName,Vehicle,acc_theta_npts,veh_spd_vec,useParallel,retainFullSimulationData,showSimulationManager)
%sm_car_sweep_ggv_pts Produce a GGV diagram through a set of virtual tests
%   [simOut, simIn, filename_ggv] = sm_car_sweep_ggv_pts(baseModelName,Vehicle,
%                    acc_theta_npts,veh_spd_vec,useParallel,
%                    retainFullSimulationData,showSimulationManager)
%
%   This function runs a series of tests to obtain the points on the
%   surface of a GGV diagram.  
% 
%   You can specify:
%       baseModelName        Main model (usually sm_car)
%       Vehicle              Vehicle dataset
%       acc_theta_npts       Number of points around the friction circle
%       veh_spd_vec          Vector of vehicle speeds (drag and downforce)
%       useParallel          true for parsim, false for sim
%       retainFullSimulationData  Optional; false (default) processes one
%                            simulation sequentially or two in parallel,
%                            retains only the final accel_xy value in
%                            SimulationMetadata.UserData, and disables
%                            Simscape logging. Set true only for small
%                            diagnostic sweeps that require all results.
%       showSimulationManager Optional; false (default) keeps the Simulation
%                            Manager closed to reduce memory use. Set true to
%                            monitor each serial or parallel simulation batch.
%
% Example:
% [simOut, simInput, filename_ggv] = sm_car_sweep_ggv_pts('sm_car',Vehicle,4,[0 15 30],false);

% Copyright 2021-2026 The MathWorks, Inc.

if nargin < 6 || isempty(retainFullSimulationData)
    retainFullSimulationData = false;
end
if nargin < 7 || isempty(showSimulationManager)
    showSimulationManager = false;
end

simulationManagerSetting = 'off';
if showSimulationManager
    simulationManagerSetting = 'on';
end

% Store generated figures and MAT files next to this sweep script rather
% than in whichever folder happens to be MATLAB's current folder.
outputFolder = fileparts(mfilename('fullpath'));

%% Model name
modelName     = [baseModelName '_test_ggv_new'];

%% Set up model
if(~bdIsLoaded(modelName))
    % If not loaded, open sm_car and resave
    % Model will be adjusted to accommodate parallel sweep
    open_system(baseModelName)
    save_system(baseModelName,modelName)
end

% Ensure Fast Restart is off so model can be properly configured
set_param(modelName,'FastRestart','off');
set_param(modelName,'SimulationMode','normal');

% Disable animation
set_param(modelName,'SimMechanicsOpenEditorOnUpdate','off');

% Remove PreLoadFcn and PostLoadFcn
% These will overwrite desired model configuration for GGV sweep
set_param(modelName,'PreLoadFcn','% PreLoadFcn Removed for GGV Sweep');
set_param(modelName,'PostLoadFcn','% PostLoadFcn Removed for GGV Sweep');

% Add annotation stating model has been modified
annotation_string = 'Model Modified for GGV Sweep';
annotation_path = [modelName '/' annotation_string];
if getSimulinkBlockHandle(annotation_path) == -1
    add_block('built-in/Note',annotation_path,...
        'FontSize',14,...
        'FontName','Arial',...
        'FontWeight','Bold',...
        'HorizontalAlignment','center',...
        'VerticalAlignment','middle',...
        'BackgroundColor','[1.000000, 0.796078, 0.800000]',...
        'Position',[492   345   700   373]);
end

% Configure model
sm_car_config_maneuver(modelName,'WOT Braking');
set_param([modelName '/Vehicle/Vehicle Constraint'],'LabelModeActiveChoice','NoYaw')
set_param([modelName '/World'],'popup_gravity','Ramp x and y components')
set_param([modelName '/Road/Input fWindCar'],...
    'fWind','[drag_frc 0 lift_frc]',...
    'tWind','10000',...
    'dWind','0');

% Ensure model is properly configured
sm_car_config_vehicle(modelName,false);

% Ensure Vehicle data structure has all required values
Vehicle = sm_car_vehcfg_checkConfig(Vehicle);

% Copy Vehicle data structure to a unique name in the workspace
% The workspace is copied to each worker.
Vehicle_GGV_Sweep = Vehicle;
assignin('base',"Vehicle_GGV_Sweep",Vehicle_GGV_Sweep)

%% Ensure simulation will run long enough
% Ensure we can reach around 3gs
accel_ramp_rate = 0.1;
assignin('base','accel_ramp_rate',accel_ramp_rate)
stop_time = 30/accel_ramp_rate;
set_param(modelName,'StopTime',num2str(stop_time));

%% Function to adjust settings for simulation
% Necessary for parsim and regular sim
% Use this function for both cases
sm_car_sweep_ggv_pts_presim(modelName, stop_time)

%% Define parameter sweep set

% Set of angles in x-y plane for acceleration
acc_theta_vec = linspace(0,2*pi,acc_theta_npts+1);      % Default 17, set lower for faster sweep
acc_theta_vec = acc_theta_vec(1:end-1);  % Do not repeat first point

% Set of vehicle speeds, used to calculate lift and drag forces
%veh_spd_vec   = linspace(0,42,6);        % Default 6, set lower for faster sweep

% Set of lift and drag forces
lift_frc_vec  = veh_spd_vec.*veh_spd_vec*...
    0.5*Vehicle.Chassis.Aero.rho_air.Value*Vehicle.Chassis.Aero.ARef.Value*Vehicle.Chassis.Aero.CL.Value;
drag_frc_vec  = sign(veh_spd_vec).*veh_spd_vec.*veh_spd_vec*...
    -0.5*Vehicle.Chassis.Aero.rho_air.Value*Vehicle.Chassis.Aero.ARef.Value*Vehicle.Chassis.Aero.CD.Value;

% Assign variables in base workspace so model can run interactively
assignin('base','acc_theta',acc_theta_vec(1));
assignin('base','lift_frc',lift_frc_vec(1));
assignin('base','drag_frc',drag_frc_vec(1));

% Number of simulations
nSims = length(acc_theta_vec)*length(veh_spd_vec);

%% Configure memory-efficient logging
% A GGV point only needs the final accel_xy value. The normal vehicle model
% logging includes several large buses and the entire Simscape network for
% every run, which makes memory usage grow with the number of simulations.
if ~retainFullSimulationData
    ggvLoggingInfo = Simulink.SimulationData.ModelLoggingInfo(modelName);
    accelSignalInfo = Simulink.SimulationData.SignalLoggingInfo( ...
        [modelName '/World/Mechanism Configuration/Variable GravityXY/Ramp1'],1);
    accelSignalInfo.LoggingInfo.DataLogging = true;
    accelSignalInfo.LoggingInfo.NameMode = true;
    accelSignalInfo.LoggingInfo.LoggingName = 'accel_xy';
    accelSignalInfo.LoggingInfo.LimitDataPoints = true;
    accelSignalInfo.LoggingInfo.MaxPoints = 2;
    ggvLoggingInfo.Signals = accelSignalInfo;
    ggvLoggingInfo.verifySignalAndModelPaths;
end

%% Set up simulation input object
% Initialise empty Simulation Input Object
simInput = Simulink.SimulationInput.empty(0,nSims);
vspd_in = zeros(1,nSims);
acc_th_in = zeros(1,nSims);
iSim = 0;

for spd_i = 1:length(veh_spd_vec)
    for acc_i = 1:length(acc_theta_vec)
        iSim = iSim+1;
        % Define the model
        simInput(iSim) = Simulink.SimulationInput(modelName);
        % Define parameter values
        simInput(iSim) = simInput(iSim).setVariable('veh_spd',veh_spd_vec(spd_i));
        simInput(iSim) = simInput(iSim).setVariable('acc_theta',acc_theta_vec(acc_i));
        simInput(iSim) = simInput(iSim).setVariable('lift_frc',lift_frc_vec(spd_i));
        simInput(iSim) = simInput(iSim).setVariable('drag_frc',drag_frc_vec(spd_i));
        % Define model settings
        simInput(iSim) = simInput(iSim).setModelParameter( ...
            'StopTime',num2str(stop_time), ...
            'SimulationMode','normal');
        if ~retainFullSimulationData
            simInput(iSim) = simInput(iSim).setModelParameter( ...
                'DataLoggingOverride',ggvLoggingInfo, ...
                'SimscapeLogType','none', ...
                'SimscapeLogSimulationStatistics','off', ...
                'SaveTime','off', ...
                'SaveOutput','off');
        end
        simInput(iSim) = simInput(iSim).setPreSimFcn(@(x) sm_car_sweep_ggv_pts_presim(modelName, stop_time));
        vspd_in(iSim) = veh_spd_vec(spd_i);
        acc_th_in(iSim) = acc_theta_vec(acc_i);
    end
end

% Save before deploying for tests
save_system(modelName);

%% Run tests and extract final acceleration
acc_xy_res = zeros(1,nSims);

if retainFullSimulationData
    executionMode = 'serial';
    if useParallel
        executionMode = 'parallel';
    end
    fprintf('GGV sweep: starting %d simulations as one %s job.\n',...
        nSims,executionMode);
    drawnow;
    fullSweepTimer = tic;
    if useParallel
        simOut = parsim(simInput,'ShowSimulationManager',simulationManagerSetting,...
            'ShowProgress','off','UseFastRestart','on',...
            'TransferBaseWorkspaceVariables','on');
    else
        simOut = sim(simInput,'ShowSimulationManager',simulationManagerSetting,...
            'ShowProgress','off','UseFastRestart','on');
    end

    for iSim = 1:nSims
        accelSignal = simOut(iSim).logsout_sm_car.get("accel_xy").Values;
        acc_xy_res(iSim) = accelSignal.Data(end);
    end
    fprintf('GGV sweep: completed all %d simulations in %.1f s.\n',...
        nSims,toc(fullSweepTimer));
else
    % Bound peak memory by releasing simulation outputs and their SDI runs
    % after each small batch. Run one case at a time sequentially, or two
    % cases at a time in parallel on a 16 GB machine.
    batchSize = 1;
    if useParallel
        batchSize = min(2,nSims);
    end
    simOut(1,nSims) = Simulink.SimulationOutput;

    for firstSim = 1:batchSize:nSims
        batchIndices = firstSim:min(firstSim+batchSize-1,nSims);
        sdiRunIdsBefore = Simulink.sdi.getAllRunIDs;

        batchTimer = tic;
        if isscalar(batchIndices)
            progressIndex = batchIndices(1);
            fprintf(['GGV sweep: running %d/%d | speed %.2f m/s | ' ...
                'accel direction %.1f deg ...\n'],...
                progressIndex,nSims,vspd_in(progressIndex),...
                acc_th_in(progressIndex)*180/pi);
        else
            fprintf('GGV sweep: running simulations %d-%d of %d in parallel:\n',...
                batchIndices(1),batchIndices(end),nSims);
            for progressIndex = batchIndices
                fprintf(['  %d/%d | speed %.2f m/s | ' ...
                    'accel direction %.1f deg\n'],...
                    progressIndex,nSims,vspd_in(progressIndex),...
                    acc_th_in(progressIndex)*180/pi);
            end
        end
        drawnow;

        if useParallel
            batchOut = parsim(simInput(batchIndices),...
                'ShowSimulationManager',simulationManagerSetting,...
                'ShowProgress','off','UseFastRestart','off',...
                'TransferBaseWorkspaceVariables','on',...
                'CleanupFcn',@() bdclose(modelName));
        else
            batchOut = sim(simInput(batchIndices),...
                'ShowSimulationManager',simulationManagerSetting,...
                'ShowProgress','off','UseFastRestart','off');
        end

        batchErrorMessage = '';
        batchErrorIndex = [];
        for batchSim = 1:numel(batchIndices)
            iSim = batchIndices(batchSim);
            if ~isempty(batchOut(batchSim).ErrorMessage)
                batchErrorIndex = iSim;
                batchErrorMessage = batchOut(batchSim).ErrorMessage;
                break
            end

            accelSignal = batchOut(batchSim).logsout_sm_car.get("accel_xy").Values;
            acc_xy_res(iSim) = accelSignal.Data(end);

            % Preserve a lightweight SimulationOutput for API compatibility.
            reducedOut = batchOut(batchSim).setUserData(acc_xy_res(iSim));
            loggedProperties = reducedOut.who;
            if ~isempty(loggedProperties)
                reducedOut = reducedOut.removeProperty(loggedProperties);
            end
            simOut(iSim) = reducedOut;
        end

        clear batchOut accelSignal reducedOut loggedProperties

        newSdiRunIds = setdiff(Simulink.sdi.getAllRunIDs,sdiRunIdsBefore);
        for runId = reshape(newSdiRunIds,1,[])
            Simulink.sdi.deleteRun(runId);
        end

        % Unload the compiled Simscape network before starting the next
        % batch. The saved sweep model is loaded again automatically.
        if bdIsLoaded(modelName)
            close_system(modelName,0);
        end

        if ~isempty(batchErrorMessage)
            error('sm_car_sweep_ggv_pts:SimulationFailed',...
                'Simulation %d failed: %s',batchErrorIndex,batchErrorMessage);
        end

        fprintf('GGV sweep: completed through %d/%d in %.1f s.\n',...
            batchIndices(end),nSims,toc(batchTimer));
    end
end

vehicle_strs = strsplit(Vehicle.config,'_');
vehicle_name = vehicle_strs{1};

GGV_data.lat_acc_pts_g   =  sin(acc_th_in).*acc_xy_res/9.81;
GGV_data.lng_acc_pts_g   = -cos(acc_th_in).*acc_xy_res/9.81;
GGV_data.veh_spd_pts_mps = vspd_in;
GGV_data.veh_spd_vec     = veh_spd_vec;
GGV_data.acc_theta_vec   = acc_theta_vec;
GGV_data.vehicle_config  = Vehicle.config;
assignin('base','GGV_data',GGV_data)
%% Plot GGV diagram
fig_h_ggv = sm_car_plot_ggv_surf(GGV_data);

%% Save results to a file
date_str = strrep(strrep(strrep( ...
    simOut(end).SimulationMetadata.TimingInfo.WallClockTimestampStop,...
    '-',''),':',''),' ','_');

resultName = ['GGV_' vehicle_name '_' date_str(1:end-2)];
filename_ggv = fullfile(outputFolder,resultName);
savefig(fig_h_ggv,[filename_ggv '.fig'])
save([filename_ggv '.mat'],'GGV_data');
fprintf('GGV results saved to:\n  %s.fig\n  %s.mat\n',...
    filename_ggv,filename_ggv);

%% Reset model
if bdIsLoaded(modelName)
    set_param(modelName,'FastRestart','off')
    set_param(modelName,'SimMechanicsOpenEditorOnUpdate','on');
end

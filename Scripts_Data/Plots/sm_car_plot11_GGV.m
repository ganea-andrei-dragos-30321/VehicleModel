% Code to plot GGV mesh from sm_car simulation results
%% Plot Description:
%
% Plot a GGV mesh using logged vehicle speed and body accelerations from a
% completed simulation. No parameter sweep or simulation is run here.
%
% Copyright 2026 The MathWorks, Inc.

% Check for simulation results
if exist('out', 'var')
    try
        logsout_sm_car = out.logsout_sm_car;
    catch
    end
end

if ~exist('logsout_sm_car', 'var')
    error('logsout_sm_car data not available. Run the simulation first, or provide out.logsout_sm_car.');
end

% Get simulation results
logsout_VehBus = logsout_sm_car.get('VehBus');
if isempty(logsout_VehBus)
    error('VehBus was not found in logsout_sm_car.');
end

[logsout_vxVeh, speed_x_signal] = getLoggedSignal( ...
    logsout_VehBus.Values, {'Chassis.Body.CG.vx', 'World.vx'});
[logsout_vyVeh, speed_y_signal] = getLoggedSignal( ...
    logsout_VehBus.Values, {'Chassis.Body.CG.vy', 'World.vy'});

sim_t = getSignalTime(logsout_vxVeh);
veh_vx = getSignalDataAtTime(logsout_vxVeh, sim_t);
veh_vy = getSignalDataAtTime(logsout_vyVeh, sim_t);
veh_spd_mps = hypot(veh_vx, veh_vy);

[lng_acc, lat_acc, acc_source] = getBodyAcceleration( ...
    logsout_VehBus.Values, sim_t);

if exist('Vehicle', 'var') && isfield(Vehicle, 'config')
    config_string = Vehicle.config;
else
    config_string = 'custom';
end

[fig_h, GGV_data] = sm_car_plot_ggv_mesh_from_points( ...
    lat_acc, lng_acc, veh_spd_mps, ...
    'VehicleConfig', config_string, ...
    'FigureName', 'h1_sm_car_ggv');

GGV_data.source.speed_x = speed_x_signal;
GGV_data.source.speed_y = speed_y_signal;
GGV_data.source.acceleration = acc_source;

fprintf('GGV mesh plotted from %d logged samples.\n', numel(veh_spd_mps));
fprintf('Speed signals: %s, %s\n', speed_x_signal, speed_y_signal);
fprintf('Acceleration source: %s\n', acc_source);

clear logsout_VehBus logsout_vxVeh logsout_vyVeh
clear speed_x_signal speed_y_signal acc_source
clear sim_t veh_vx veh_vy veh_spd_mps lng_acc lat_acc config_string

function [signal, signal_path] = getLoggedSignal(values, candidate_paths)
for path_i = 1:numel(candidate_paths)
    this_path = candidate_paths{path_i};
    [found, this_signal] = tryGetNestedSignal(values, this_path);
    if found
        signal = this_signal;
        signal_path = this_path;
        return
    end
end

error('None of these logged signals were found: %s', ...
    strjoin(candidate_paths, ', '));
end

function [found, signal] = tryGetNestedSignal(values, signal_path)
signal = values;
path_parts = strsplit(signal_path, '.');
found = true;

for part_i = 1:numel(path_parts)
    try
        signal = signal.(path_parts{part_i});
    catch
        found = false;
        signal = [];
        return
    end
end
end

function signal_time = getSignalTime(signal)
try
    signal_time = signal.Time(:);
catch
    error('Logged signal does not include a Time vector.');
end
end

function signal_data = getSignalDataAtTime(signal, target_time)
signal_time = getSignalTime(signal);
signal_data = squeeze(signal.Data);
signal_data = signal_data(:);

if numel(signal_data) ~= numel(signal_time)
    error('Logged signal data length does not match its time vector.');
end

if isequal(signal_time, target_time)
    return
end

[signal_time_unique, unique_ind] = unique(signal_time);
signal_data_unique = signal_data(unique_ind);
signal_data = interp1(signal_time_unique, signal_data_unique, ...
    target_time, 'linear', 'extrap');
end

function [lng_acc, lat_acc, acc_source] = getBodyAcceleration(values, target_time)
try
    [logsout_gx, gx_signal] = getLoggedSignal(values, ...
        {'Chassis.Body.CG.gx'});
    [logsout_gy, gy_signal] = getLoggedSignal(values, ...
        {'Chassis.Body.CG.gy'});
    lng_acc = getSignalDataAtTime(logsout_gx, target_time);
    lat_acc = getSignalDataAtTime(logsout_gy, target_time);
    acc_source = sprintf('%s, %s', gx_signal, gy_signal);
    return
catch
end

[logsout_vxWorld, vx_signal] = getLoggedSignal(values, {'World.vx'});
[logsout_vyWorld, vy_signal] = getLoggedSignal(values, {'World.vy'});
[logsout_yaw, yaw_signal] = getLoggedSignal(values, ...
    {'Chassis.Body.CG.aYaw', 'World.aYaw'});

vx_world = getSignalDataAtTime(logsout_vxWorld, target_time);
vy_world = getSignalDataAtTime(logsout_vyWorld, target_time);
yaw = getSignalDataAtTime(logsout_yaw, target_time);

ax_world = gradient(vx_world, target_time);
ay_world = gradient(vy_world, target_time);

lng_acc = cos(yaw).*ax_world + sin(yaw).*ay_world;
lat_acc = -sin(yaw).*ax_world + cos(yaw).*ay_world;
acc_source = sprintf('derived from %s, %s, %s', ...
    vx_signal, vy_signal, yaw_signal);
end

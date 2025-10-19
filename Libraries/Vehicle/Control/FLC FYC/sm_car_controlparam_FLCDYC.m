function control_param = sm_car_controlparam_FLCDYC
%% Control parameters

control_param.Name = 'DYC_FLC';

%% Parameters for other components in the control module


% Parameters for four-wheel steering algorithm
str_gain_pts       = [0   -0.3000   -0.3000   -0.2000    0.3000    0.3000         0         0];
veh_spd_kmh_pts    = [0    5.0000   10.0000   25.0000   50.0000   70.0000   95.0000  180.0000];
veh_spd_kmh_interp = [linspace(0,100,20) 180];
str_gain_vec       = interp1(veh_spd_kmh_pts,str_gain_pts,veh_spd_kmh_interp,'pchip');

control_param.Steer.Gain.vVehicle.Value = veh_spd_kmh_interp;
control_param.Steer.Gain.vVehicle.Units = 'km/h';
control_param.Steer.Gain.n.Value = str_gain_vec;
control_param.Steer.fActuatorCutoff.Value = 50;
control_param.Steer.fActuatorCutoff.Units = 'Hz';
control_param.Steer.Limits.aUpper.Value   = 10*(pi/180);
control_param.Steer.Limits.aUpper.Units   = 'rad';
control_param.Steer.Limits.aLower.Value   = -10*(pi/180);
control_param.Steer.Limits.aUpper.Units   = 'rad';

%% Parameters for model control
Vehicle = evalin('base','Vehicle');

tire_param = simscape.multibody.tirread(eval('which(''fsae190_50R10.tir'')'));
rwheel=tire_param.DIMENSION.UNLOADED_RADIUS;

mcg=Vehicle.Chassis.Body.m.Value;                           % mass at center of G       
L=-Vehicle.Chassis.Body.sAxle2.Value(1);                    % wheelbase 
a=-Vehicle.Chassis.Body.sCG.Value(1);                       % distance from front axle to CoG
b=L-a;
c_alpha_f=Vehicle.Chassis.TireA1.CornerringStiffnes.Value;
c_alpha_r=Vehicle.Chassis.TireA2.CornerringStiffnes.Value  ;
Gr=1/Vehicle.Powertrain.Driveline.GearboxR2.ratio.Value;    % gear ratio for torque
H=Vehicle.Chassis.Body.sCG.Value(3);                        % CoG height
tr=Vehicle.Chassis.Body.TrackRear.Value;                    % rear track width
 

control_param.RearTrack=Vehicle.Chassis.Body.TrackRear.Value;
control_param.WheelRad=rwheel;
control_param.FuzzySystem=readfis('FIS_DYC');
control_param.GearRatio=Vehicle.Powertrain.Driveline.GearboxL2.ratio.Value;
control_param.StrWheelRatio=0.165;
control_param.UndersteerGradient= mcg / L * (b / c_alpha_f - a / c_alpha_r);
control_param.Wheelbase=L;
control_param.F=rwheel / tr / Gr;
control_param.Mass=mcg;
control_param.TrackFrontToCG=a;
control_param.Height=H;
control_param.g=9.81;
control_param.MotorTrq=Vehicle.Powertrain.Power.MotorL2.TorqueSpd.trq.Value;
control_param.MotorW=Vehicle.Powertrain.Power.MotorL2.TorqueSpd.w.Value;

% Slip Control Coefficients
control_param.Correction.Inc=1.001;
control_param.Correction.Dec=0.999;

%% Tunable Control Param
control_param.SlipTh=0.1;
control_param.KpMoment=100;



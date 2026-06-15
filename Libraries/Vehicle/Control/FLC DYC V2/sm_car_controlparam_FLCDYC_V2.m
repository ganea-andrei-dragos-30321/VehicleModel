function control_param = sm_car_controlparam_FLCDYC_V2
%% Control parameters

control_param.Name = 'DYC_FLC_V2';

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

rwheel=0.263;

mcg = 320;                           % mass at center of G       
L = 1.578;                    % wheelbase 
a = -Vehicle.Chassis.Body.sCG.Value(1);                       % distance from front axle to CoG
b = L-a;  
c_alpha_f = 34000;                                            % front cornering stiffness
c_alpha_r = 62000;                                            % rear cornering stiffness
Gr = 1/Vehicle.Powertrain.Driveline.Gearbox.ratio.Value;      % gear ratio for torque
tr = Vehicle.Chassis.Body.TrackRear.Value;                    % rear track width
 

control_param.FuzzySystem_1 = load('FIS_DYC.mat');
control_param.FuzzySystem_1 = control_param.FuzzySystem_1.FuzzySystem;
control_param.FuzzySystem_2 = load('FIS_DYC_2.mat');
control_param.FuzzySystem_2 = control_param.FuzzySystem_2.FIS_DYC_2;
control_param.FuzzySystem_3 = load('FIS_DYC_3.mat');
control_param.FuzzySystem_3 = control_param.FuzzySystem_3.FIS_DYC_3;
control_param.StrWheelRatio = 1/5.71;
control_param.UndersteerGradient = mcg / L * (b / c_alpha_f - a / c_alpha_r);
control_param.F = rwheel / tr * Gr;

control_param.WheelRad = rwheel;
control_param.GearRatio = Vehicle.Powertrain.Driveline.Gearbox.ratio.Value;
control_param.MotorTrq = Vehicle.Powertrain.Power.Motor.TorqueSpd.trq.Value;
control_param.MotorW = Vehicle.Powertrain.Power.Motor.TorqueSpd.w.Value;
control_param.Tmax = max(control_param.MotorTrq);

% Vehicle Dynamics and Aero Parameters
control_param.RearTrack = 1.248;
control_param.FrontTrackToCG = 0.8232;
control_param.FrontTrackToCoP = 0.707;
control_param.FrontalArea = 1.2;

% PID Control Gains
control_param.Proportional_P = 800;
control_param.Integral_I = 6000;
control_param.Derivative_D = 11;
control_param.Filter_N = 100;

% TV Control gains 


% Simulation and Physical Constants
control_param.ActivationVelocity = 0.7;
control_param.LiftCoef = -2.15;
control_param.GravitationalAcc = 9.81;
control_param.CGHeight = 0.3583;
control_param.Wheelbase = 1.578;
control_param.Mass = 320;
control_param.AirDensity = 1.226;
control_param.CalphaF = 34000;

% Slip Refence Table
control_param.SlipRef = [0.08;0.08;0.09;0.095;0.093;0.092;0.091;0.09;0.09;0.09;0.094;0.098;0.104;0.112;0.126;0.154;0.2;0.12];
control_param.LoadRef = [0;400;500;600;700;800;900;1000;1100;1200;1300;1400;1500;1600;1700;1800;1900;2000];





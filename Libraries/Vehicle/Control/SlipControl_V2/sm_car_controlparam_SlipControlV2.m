function control_param = sm_car_controlparam_SlipControlV2
%% Control parameters

control_param.Name = 'SlipControlV2';

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

% Drivetrain Parameters
control_param.WheelRad = rwheel;
control_param.GearRatio = Vehicle.Powertrain.Driveline.Gearbox.ratio.Value;
control_param.MotorTrq = Vehicle.Powertrain.Power.Motor.TorqueSpd.trq.Value;
control_param.MotorW = Vehicle.Powertrain.Power.Motor.TorqueSpd.w.Value;
control_param.Tmax = max(control_param.MotorTrq);

% Vehicle Dynamics and Aero Parameters
control_param.RearTrack = 1.248;
control_param.FrontTrackToCG = 0.823;
control_param.FrontTrackToCoP = 0.8;
control_param.FrontalArea = 1.2;

% PID Control Gains
control_param.Proportional_P = 50;
control_param.Integral_I = 200;
control_param.Derivative_D = 5;

% Simulation and Physical Constants
control_param.ActivationVelocity = 0.7;
control_param.LiftCoef = -2.15;
control_param.GravitationAcc = 9.81;
control_param.CGHeight = 0.315;
control_param.Wheelbase = 1.575;
control_param.Mass = 315;
control_param.AirDensity = 1.226;

% Slip Refence Table
control_param.SlipRef = [0.08;0.08;0.152;0.116;0.102;0.096;0.092;0.09;0.09;0.09;0.094;0.098;0.104;0.112;0.126;0.154;0.232;0.1];
control_param.LoadRef = [0;400;500;600;700;800;900;1000;1100;1200;1300;1400;1500;1600;1700;1800;1900;2000];



function control_param = sm_car_controlparam_NoIMU
%% Control parameters

control_param.Name = 'NoIMU';


% Copy motor lookup table exactly
motor = evalin('base','Vehicle.Powertrain.Power.Motor');
control_param.Tmax=max(motor.TorqueSpd.trq.Value);
control_param.CurrentTrqConst= motor.TorqueConstant.Value; % change to our value once motors are placed or for export


control_param.I0Load= 0; % change to our value once motors are placed or for export
control_param.w0Load= 0; % change to our value once motors are placed or for export
control_param.FuzzySystem=readfis('FIS_No_IMU');
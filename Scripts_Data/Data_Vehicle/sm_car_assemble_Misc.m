function Vehicle = sm_car_assemble_Misc(Vehicle)

%% Body Misc
Vehicle.Chassis.Body.BodyGeometry = struct;
Vehicle.Chassis.Body.BodyGeometry.class = struct;
Vehicle.Chassis.Body.BodyGeometry.class.Value = 'CAD_FSAE_Achilles';
Vehicle.Chassis.Body.BodyGeometry.sOffset = struct;
Vehicle.Chassis.Body.BodyGeometry.sOffset.Units = 'm';
Vehicle.Chassis.Body.BodyGeometry.sOffset.Comments = '';
Vehicle.Chassis.Body.BodyGeometry.sOffset.Value = ...
    [-0.5375 0 0];
Vehicle.Chassis.Body.BodyGeometry.aOffset = struct;
Vehicle.Chassis.Body.BodyGeometry.aOffset.Units = 'Yaw-Pitch-Roll';
Vehicle.Chassis.Body.BodyGeometry.aOffset.Comments = '';
Vehicle.Chassis.Body.BodyGeometry.aOffset.Value = ...
    [0 0 0];
Vehicle.Chassis.Body.BodyGeometry.Color = struct;
Vehicle.Chassis.Body.BodyGeometry.Color.Units = '[RGB]';
Vehicle.Chassis.Body.BodyGeometry.Color.Comments = '';
Vehicle.Chassis.Body.BodyGeometry.Color.Value = ...
    [0.1 0.5 0.9];
Vehicle.Chassis.Body.BodyGeometry.Opacity = struct;
Vehicle.Chassis.Body.BodyGeometry.Opacity.Units = '(0-1)';
Vehicle.Chassis.Body.BodyGeometry.Opacity.Comments = '';
Vehicle.Chassis.Body.BodyGeometry.Opacity.Value = 1;
Vehicle.Chassis.Body.BodyGeometry.AeroColor = struct;
Vehicle.Chassis.Body.BodyGeometry.AeroColor.Units = '[RGB]';
Vehicle.Chassis.Body.BodyGeometry.AeroColor.Comments = '';
Vehicle.Chassis.Body.BodyGeometry.AeroColor.Value = ...
    [0.095 0.2 0.3];
Vehicle.Chassis.Body.BodyGeometry.AeroOpacity = struct;
Vehicle.Chassis.Body.BodyGeometry.AeroOpacity.Units = '(0-1)';
Vehicle.Chassis.Body.BodyGeometry.AeroOpacity.Comments = '';
Vehicle.Chassis.Body.BodyGeometry.AeroOpacity.Value = 1;
Vehicle.Chassis.Body.BodyGeometry.Type = 'BodyGeometry';
Vehicle.Chassis.Body.BodyGeometry.Instance = 'CAD_FSAE_Achilles';
Vehicle.Chassis.Body.BodyLoad = struct;
Vehicle.Chassis.Body.BodyLoad.class = struct;
Vehicle.Chassis.Body.BodyLoad.class.Value = 'None';
Vehicle.Chassis.Body.BodyLoad.Type = 'BodyLoad';
Vehicle.Chassis.Body.BodyLoad.Instance = 'None';

%% Steering Misc
Vehicle.Chassis.SuspA1.Steer.DriverHuman = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.class = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.class.Value = 'None';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.s = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.s.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.s.Comments = '';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.s.Value = ...
    [-1.26656038245259 0.376762948446593 0.62577262194717];
Vehicle.Chassis.SuspA1.Steer.DriverHuman.a = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.a.Units = 'deg';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.a.Comments = ...
    'Roll-Pitch-Yaw, applied Y->P->R';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.a.Value = ...
    [0 0 0];
Vehicle.Chassis.SuspA1.Steer.DriverHuman.rho = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.rho.Units = 'kg/m^3';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.rho.Comments = ...
    'Use to adjust passenger mass';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.rho.Value = 1000;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.aHeadInclination = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.aHeadInclination.Units = 'deg';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.aHeadInclination.Comments = '';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.aHeadInclination.Value = 15;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Color = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Color.Units = '[RGB] (0-1)';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Color.Comments = '[RGB]';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Color.Value = ...
    [0.7921 0.8196 0.9333];
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Opacity = struct;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Opacity.Units = '(0-1)';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Opacity.Comments = '';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Opacity.Value = 1;
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Type = 'DriverHuman';
Vehicle.Chassis.SuspA1.Steer.DriverHuman.Instance = 'None';


end
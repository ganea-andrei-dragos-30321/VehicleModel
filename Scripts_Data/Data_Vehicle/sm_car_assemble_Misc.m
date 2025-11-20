function Vehicle = sm_car_assemble_Misc(Vehicle)

% Temporary until steering will be fixed
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

end
function Vehicle = sm_car_assemble_Steering(filename,Vehicle)

% Temporary until steering will be fixed
hrdPt=read_excel(filename,'HardpointsFr','UseRowNames',true)./1000;
pinionIncl=-atan((hrdPt{'upperCol','X'}-hrdPt{'steerRack','X'})/(hrdPt{'upperCol','Z'}-hrdPt{'steerRack','Z'}));
Vehicle.Chassis.SuspA1.Steer = struct;
Vehicle.Chassis.SuspA1.Steer.class = struct;
Vehicle.Chassis.SuspA1.Steer.class.Value = 'WheelDrivenRack1UJoint1';
Vehicle.Chassis.SuspA1.Steer.Rack = struct;
Vehicle.Chassis.SuspA1.Steer.Rack.sMount = struct;
Vehicle.Chassis.SuspA1.Steer.Rack.sMount.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Rack.sMount.Comments = 'HPRack';
Vehicle.Chassis.SuspA1.Steer.Rack.sMount.Value = ...
  hrdPt{'steerRack',:};
Vehicle.Chassis.SuspA1.Steer.Rack.m = struct;
Vehicle.Chassis.SuspA1.Steer.Rack.m.Units = 'kg';
Vehicle.Chassis.SuspA1.Steer.Rack.m.Comments = 'Mass';
Vehicle.Chassis.SuspA1.Steer.Rack.m.Value = 1.8;
Vehicle.Chassis.SuspA1.Steer.Rack.fActuatorCutoff = struct;
Vehicle.Chassis.SuspA1.Steer.Rack.fActuatorCutoff.Units = 'Hz';
Vehicle.Chassis.SuspA1.Steer.Rack.fActuatorCutoff.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Rack.fActuatorCutoff.Value = 50;
Vehicle.Chassis.SuspA1.Steer.Wheel = struct;
Vehicle.Chassis.SuspA1.Steer.Wheel.sMount = struct;
Vehicle.Chassis.SuspA1.Steer.Wheel.sMount.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Wheel.sMount.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Wheel.sMount.Value = ...
  hrdPt{'steerWheel',:};
Vehicle.Chassis.SuspA1.Steer.Wheel.sUpperCol = struct;
Vehicle.Chassis.SuspA1.Steer.Wheel.sUpperCol.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Wheel.sUpperCol.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Wheel.sUpperCol.Value = ...
  hrdPt{'upperCol',:};
Vehicle.Chassis.SuspA1.Steer.Wheel.aAxis = struct;
Vehicle.Chassis.SuspA1.Steer.Wheel.aAxis.Units = 'rad';
Vehicle.Chassis.SuspA1.Steer.Wheel.aAxis.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Wheel.aAxis.Value = ...
 -atan((hrdPt{'steerWheel','Z'}-hrdPt{'upperCol','Z'})/(hrdPt{'steerWheel','X'}-hrdPt{'upperCol','X'}));
Vehicle.Chassis.SuspA1.Steer.Wheel.m = struct;
Vehicle.Chassis.SuspA1.Steer.Wheel.m.Units = 'kg';
Vehicle.Chassis.SuspA1.Steer.Wheel.m.Comments = 'Mass';
Vehicle.Chassis.SuspA1.Steer.Wheel.m.Value = 0.7;
Vehicle.Chassis.SuspA1.Steer.Wheel.class = struct;
Vehicle.Chassis.SuspA1.Steer.Wheel.class.Value = 'FSAE';
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper = struct;
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.m = struct;
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.m.Units = 'kg';
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.m.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.m.Value = 0.4;
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.xLength = struct;
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.xLength.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.xLength.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Shaft_Upper.xLength.Value = ((hrdPt{'steerWheel','X'}-hrdPt{'upperCol','X'})^2+(hrdPt{'steerWheel','X'}-hrdPt{'upperCol','X'})^2)^(1/2);
Vehicle.Chassis.SuspA1.Steer.Shaft_Lower = struct;
Vehicle.Chassis.SuspA1.Steer.Shaft_Lower.m = struct;
Vehicle.Chassis.SuspA1.Steer.Shaft_Lower.m.Units = 'kg';
Vehicle.Chassis.SuspA1.Steer.Shaft_Lower.m.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Shaft_Lower.m.Value = 0.4;
Vehicle.Chassis.SuspA1.Steer.Pinion = struct;
Vehicle.Chassis.SuspA1.Steer.Pinion.xRad = struct;
Vehicle.Chassis.SuspA1.Steer.Pinion.xRad.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Pinion.xRad.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Pinion.xRad.Value = 0.01365;
Vehicle.Chassis.SuspA1.Steer.Pinion.sMount = struct;
Vehicle.Chassis.SuspA1.Steer.Pinion.sMount.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Pinion.sMount.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Pinion.sMount.Value = ...
  hrdPt{'steerPinion',:}-[cos(pinionIncl)*Vehicle.Chassis.SuspA1.Steer.Pinion.xRad.Value,0,sin(pinionIncl)*Vehicle.Chassis.SuspA1.Steer.Pinion.xRad.Value];
Vehicle.Chassis.SuspA1.Steer.Pinion.m = struct;
Vehicle.Chassis.SuspA1.Steer.Pinion.m.Units = 'kg';
Vehicle.Chassis.SuspA1.Steer.Pinion.m.Comments = '';
Vehicle.Chassis.SuspA1.Steer.Pinion.m.Value = 0.05;
Vehicle.Chassis.SuspA1.Steer.Ratio_Table = struct;
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.aWheel = struct;
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.aWheel.Units = 'rad';
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.aWheel.Comments = ...
  'Wheel Angle - reference only -- Modify to get value form table';
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.aWheel.Value = linspace(-2.689,2.689,21);
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.xRack = struct;
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.xRack.Units = 'm';
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.xRack.Comments = ...
  'Rack Displacement - reference only--Modify to get value form table';
Vehicle.Chassis.SuspA1.Steer.Ratio_Table.xRack.Value = linspace(-0.032,0.032,21);
Vehicle.Chassis.SuspA1.Steer.Type = 'Steer';
Vehicle.Chassis.SuspA1.Steer.Instance = ...
  'WheelDrivenRack1UJoint_Ch2_Achilles';
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
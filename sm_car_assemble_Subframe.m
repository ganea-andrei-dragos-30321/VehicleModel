function sm_car_assemble_Subframe(inputArg1,inputArg2)

Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.class = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.class.Value = ...
  'Rigid_1Rev';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Law.Comments = ...
  'Linear / Table /Maxwell SLS';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Linear.K = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Linear.K.Units = ...
  'N/mm';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Linear.K.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Linear.K.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.x = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.x.Units = ...
  'mm';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.x.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.x.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.k1 = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.k1.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.k1.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.k1.Value = 3013.9;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.b1 = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.b1.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.b1.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.b1.Value = 11471;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.x = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.x.Units = ...
  'mm';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.x.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.x.Value = ...
  [-3 -1.5 1.5 3];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialSpring.Maxwell.f.Value = ...
  [-6555 -2622 2622 6555];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Law.Comments = ...
  'Linear / Table';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Linear.d = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Linear.d.Units = ...
  'N/(m/s)';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Linear.d.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Linear.d.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.v = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.v.Units = ...
  'm/s';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.v.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.v.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.RadialDamper.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Law.Comments = ...
  'Linear / Table';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Linear.K = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Linear.K.Units = ...
  'N/mm';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Linear.K.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Linear.K.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.x = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.x.Units = ...
  'mm';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.x.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.x.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialSpring.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Law.Comments = ...
  'Linear / Table';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Linear.d = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Linear.d.Units = ...
  'N/(m/s)';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Linear.d.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Linear.d.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.v = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.v.Units = ...
  'm/s';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.v.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.v.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.AxialDamper.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.Type = ...
  'Subframe_Conn';
Vehicle.Chassis.SuspA1.Linkage.Upper_Arm_to_Subframe.Instance = ...
  'Bushing_Sedan_UA';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.class = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.class.Value = ...
  'Rigid_1Rev';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Law.Comments = ...
  'Linear / Table /Maxwell SLS';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Linear.K = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Linear.K.Units = ...
  'N/mm';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Linear.K.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Linear.K.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.x = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.x.Units = ...
  'mm';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.x.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.x.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.k1 = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.k1.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.k1.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.k1.Value = 3013.9;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.b1 = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.b1.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.b1.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.b1.Value = 11471;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.x = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.x.Units = ...
  'mm';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.x.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.x.Value = ...
  [-3 -1.5 1.5 3];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialSpring.Maxwell.f.Value = ...
  [-6555 -2622 2622 6555];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Law.Comments = ...
  'Linear / Table';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Linear.d = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Linear.d.Units = ...
  'N/(m/s)';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Linear.d.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Linear.d.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.v = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.v.Units = ...
  'm/s';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.v.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.v.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.RadialDamper.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Law.Comments = ...
  'Linear / Table';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Linear.K = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Linear.K.Units = ...
  'N/mm';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Linear.K.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Linear.K.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.x = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.x.Units = ...
  'mm';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.x.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.x.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialSpring.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Law = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Law.Units = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Law.Comments = ...
  'Linear / Table';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Law.Value = ...
  'Linear';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Linear = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Linear.d = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Linear.d.Units = ...
  'N/(m/s)';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Linear.d.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Linear.d.Value = 2e4;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.v = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.v.Units = ...
  'm/s';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.v.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.v.Value = ...
  [-4 -3 -2 -1 0 1 2 3 4];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.f = struct;
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.f.Units = 'N';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.f.Comments = '';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.AxialDamper.Table.f.Value = ...
  [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.Type = ...
  'Subframe_Conn';
Vehicle.Chassis.SuspA1.Linkage.Lower_Arm_to_Subframe.Instance = ...
  'Bushing_Sedan_LA';

end
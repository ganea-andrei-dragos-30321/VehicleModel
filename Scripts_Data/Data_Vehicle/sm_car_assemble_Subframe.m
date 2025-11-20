function Vehicle = sm_car_assemble_Subframe(Vehicle, conn)
%% Input handling 
if nargin ~= 2
    error('Invalid number of arguments. Expected 2, but got %d.', naragin);
elseif strcmp(conn,{'Rigid_1Rev','Rigid_2Rev','Bushing_AxRad'})
    error('Invalid connection type "%s", choose one of "Rigid_1Rev, Rigid_2Rev, Bushing_AxRad"', conn);
end

%% Bushing stifness and damping values
bushing_K = 2e4;
bushing_d = 2e4;

Susp = {'SuspA1', 'SuspA2'};
Arm = {'Upper_Arm_to_Subframe','Lower_Arm_to_Subframe'};

%% Subframe connection assign
if strcmp(conn,'Rigid_1Rev') || strcmp(conn,'Rigid_2Rev')
    for i=1:2
        for j=1:2
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j})= struct;
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).class = struct;
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).class.Value = ...
              conn;
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).Type = ...
              'Subframe_Conn';
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).Instance = ...
              conn;
        end
    end
else
    for i=1:2
        for j=1:2
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j})= struct;
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).class = struct;
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).class.Value = ...
              conn;
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).Type = ...
              'Subframe_Conn';
             Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).Instance = ...
              conn;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Law = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Law.Units = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Law.Comments = ...
              'Linear / Table /Maxwell SLS';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Law.Value = ...
              'Linear';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Linear = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Linear.K = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Linear.K.Units = ...
              'N/mm';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Linear.K.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Linear.K.Value = bushing_K;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.x = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.x.Units = ...
              'mm';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.x.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.x.Value = ...
              [-4 -3 -2 -1 0 1 2 3 4];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.f = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.f.Units = 'N';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.f.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Table.f.Value = ...
              [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.k1 = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.k1.Units = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.k1.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.k1.Value = 3013.9;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.b1 = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.b1.Units = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.b1.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.b1.Value = 11471;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.x = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.x.Units = ...
              'mm';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.x.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.x.Value = ...
              [-3 -1.5 1.5 3];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.f = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.f.Units = 'N';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.f.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialSpring.Maxwell.f.Value = ...
              [-6555 -2622 2622 6555];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Law = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Law.Units = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Law.Comments = ...
              'Linear / Table';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Law.Value = ...
              'Linear';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Linear = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Linear.d = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Linear.d.Units = ...
              'N/(m/s)';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Linear.d.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Linear.d.Value = bushing_d;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.v = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.v.Units = ...
              'm/s';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.v.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.v.Value = ...
              [-4 -3 -2 -1 0 1 2 3 4];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.f = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.f.Units = 'N';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.f.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).RadialDamper.Table.f.Value = ...
              [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Law = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Law.Units = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Law.Comments = ...
              'Linear / Table';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Law.Value = ...
              'Linear';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Linear = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Linear.K = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Linear.K.Units = ...
              'N/mm';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Linear.K.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Linear.K.Value = bushing_K;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.x = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.x.Units = ...
              'mm';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.x.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.x.Value = ...
              [-4 -3 -2 -1 0 1 2 3 4];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.f = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.f.Units = 'N';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.f.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialSpring.Table.f.Value = ...
              [-4000 -2750 -1500 -500 0 500 1500 2750 4000];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Law = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Law.Units = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Law.Comments = ...
              'Linear / Table';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Law.Value = ...
              'Linear';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Linear = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Linear.d = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Linear.d.Units = ...
              'N/(m/s)';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Linear.d.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Linear.d.Value = bushing_d;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.v = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.v.Units = ...
              'm/s';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.v.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.v.Value = ...
              [-4 -3 -2 -1 0 1 2 3 4];
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.f = struct;
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.f.Units = 'N';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.f.Comments = '';
            Vehicle.Chassis.(Susp{i}).Linkage.(Arm{j}).AxialDamper.Table.f.Value = ...
              [-4000 -2750 -1500 -500 0 500 1500 2750 4000];

        end
    end
end

end
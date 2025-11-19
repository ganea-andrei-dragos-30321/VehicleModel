function [Vehicle] = sm_car_read_database

%% Most likely only keep this but keep everything for now

% Find vehicle data files

vehicle_data_file_list = dir('**/sm_car_ARTTU_*.xlsx');
if isempty(vehicle_data_file_list)
    error('No ARTTU vehicle data found');
end

% Go through files to get file names and category and initialize Vehicle
% struct
for i=1: size(vehicle_data_file_list,1)
    data_file_name(i)=sort({vehicle_data_file_list(i).name});
    data_file_categ(i)=erase(erase(data_file_name(i),'sm_car_ARTTU_'),'.xlsx');

    disp(['Importing ',  data_file_categ{i},  ' data'])

    subsystemData=import_excel(data_file_name{i});
    Vehicle.(data_file_categ{i})=subsystemData;
    
    disp('Import completed')

    % Check import
end

%% Help functions for assembly
Vehicle.config = 'Achilles_DWishbone';
% Subframe connections assembly
Vehicle = sm_car_assemble_Subframe(Vehicle, 'Rigid_1Rev');

% Steering assembly ( Temporarry )
Vehicle = sm_car_assemble_Steering('ARTTU.xlsx', Vehicle);

Vehicle = sm_car_assemble_Misc(Vehicle);
Vehicle.Brakes = Vehicle.Brakes.Brakes;

% Set derived files from within Vehicle data structure
Vehicle = addfieldVehicleDW(Vehicle);

end
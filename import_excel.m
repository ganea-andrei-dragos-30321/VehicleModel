function [DataBus]=import_excel(filename,sheets)
filename= 'sm_car_ARTTU_Brakes.xlsx';
DataBus=struct();
% Ignore sheets for hardpoints
if nargin == 1 || ~isempty(sheets)
    sheets = sheetnames(filename);
end

if ~isempty(sheets(sheets=='HardpointsFr'))
   sheets= erase(sheets,'HardpointsFr');
end
if ~isempty(sheets(sheets=='HardpointsRr'))
    sheets= erase(sheets,'HardpointsRr');
end

%figure out how to read sheets
% 
for subsystem=1:length(sheets)

    % Read the current sheet type, instance and class 
    currentSheet = sheets{subsystem};
    type = readtable(filename, 'Sheet', currentSheet, 'Range', 'A1:E4');
    field = type{:,1};
    
    % Write type, instance, class in DataBus struct
    for i=1:length(field)
    DataBus.(currentSheet).(field{i})=type{i,3};
    end

    % Read additional data from the current sheet
    sheetData = readtable(filename, 'Sheet', currentSheet, 'Range', 'A5:E100');
    sheetData(all(ismissing(sheetData), 2), :) = []; % Remove empty rows

    % Autocomplete excel merged cells in category field
    for i=1:size(sheetData,1)
        if ~isempty(sheetData.Var1{i})
            temp=sheetData.Var1{i};
        else
            sheetData.Var1{i}=temp;
        end
    end
    clear temp;

    % Add data from sheet to DataBus struct
    for i=1:size(sheetData)
    
    % Recursive way to read struct inside structs
    if  strcmp(sheetData.Var4{i},'SHEET')

        [DataBus]=import_excel(filename,sheets);
    % another case for tables to read data that cannot be put in one cell
    else
        DataBus.(currentSheet).(sheetData.Var1{i}).(sheetData.Var2{i}) = ...
            struct('Value',sheetData.Var3{i},'Unit',sheetData.Var4{i},'Comments',sheetData.Var5{i});

    
    end
    end

    % Store additional data in DataBus struct
    DataBus.(currentSheet).AdditionalData = sheetData;
end
% test=readtable("sm_car_ARTTU_Brakes.xlsx",'Range','A5:E100','Sheet',sheets);
% test(all(ismissing(test), 2), :) = [];
% for i=1:size(test,1)
% if ~isempty(test.Var1{i})
% temp=test.Var1{i};
% else
% test.Var1{i}=temp;
% end
% end
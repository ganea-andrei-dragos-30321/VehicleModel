function [DataBus]=import_excel(filename,sheets)
DataBus=struct();
% Ignore sheets for hardpoints
if nargin == 1 || isempty(sheets)
    sheets = sheetnames(filename);
end

if nargin == 1 & ~isempty(sheets(sheets=='HardpointsFr'))
   sheets= setdiff(sheets,'HardpointsFr');
end
if nargin == 1 & ~isempty(sheets(sheets=='HardpointsRr'))
    sheets= setdiff(sheets,'HardpointsRr');
end
if nargin == 1 & ~isempty(sheets(sheets=='Info'))
    sheets= setdiff(sheets,'Info');
end

allSheets = sheets;
referencedSheets = string([]);

for s = 1:numel(allSheets)
    currentSheet = allSheets{s};
    opts = detectImportOptions(filename, 'Sheet', currentSheet, 'Range', 'A5:E100');
    opts.VariableNames = ["Var1", "Var2", "Var3", "Var4", "Var5"];
    opts = setvartype(opts, opts.VariableNames, 'string');
    opts = setvaropts(opts, opts.VariableNames, 'FillValue', "");
    sheetData = readtable(filename, opts);

    % Collect sheets referenced as 'SHEET'
    referencedSheets = [referencedSheets; sheetData.Var3(sheetData.Var4 == "SHEET")];
end

% ✅ Clean referenced list
referencedSheets = unique(strtrim(referencedSheets));
referencedSheets = referencedSheets(referencedSheets ~= "");
referencedSheets = rmmissing(referencedSheets);

% ✅ Remove them from the main list
sheets = setdiff(sheets, referencedSheets);

%figure out how to read sheets
% 
for subsystem=1:length(sheets)

    % Read the current sheet type, instance and class 
    currentSheet = sheets{subsystem};
    type = readtable(filename, 'Sheet', currentSheet, 'Range', 'A1:E4');
    field = type{:,1};
    
    % Write type, instance, class in DataBus struct
    for i=1:length(field)
    DataBus.(currentSheet).(field{i}).Value=cell2mat(type{i,3});
    end

    % Read additional data from the current sheet
    opts = detectImportOptions(filename, 'Sheet', currentSheet, ...
            'Range', 'A5:E100');
    opts.VariableNames = ["Var1", "Var2", "Var3", "Var4", "Var5"];
    opts = setvartype(opts, opts.VariableNames, 'char');
    opts.DataRange = 'A5:E100'; 
    opts = setvaropts(opts, opts.VariableNames, 'FillValue', '');
    sheetData = readtable(filename,opts);
    sheetData(all(table2array(varfun(@(x) strlength(x) == 0, sheetData)), 2), :) = [];

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
    for i=1:size(sheetData,1)
    
        % Recursive way to read struct inside structs
        if  strcmp(sheetData.Var4{i},'SHEET')
    
            DataBus.(currentSheet).(sheetData.Var1{i})=import_excel(filename,sheetData.Var3(i));
        % another case for tables to read data that cannot be put in one cell
        else

            val = sheetData.Var3{i};
        
            if isstring(val) || ischar(val)
            txt = strtrim(val);   % remove leading/trailing spaces
        
            % Check for [ ... ] pattern
            if startsWith(txt, "[") && endsWith(txt, "]")
                txt = extractBetween(txt, "[", "]");  % get inner text
                txt = strrep(txt, ",", ".");          % replace commas with dots for safety
  
            end
                val=str2num(txt);
                
            end
            clear txt;
            DataBus.(currentSheet).(sheetData.Var1{i}).(sheetData.Var2{i}) = ...
                struct('Value',val,'Unit',sheetData.Var4(i),'Comments',sheetData.Var5(i));
    
        
        end
    end

end
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
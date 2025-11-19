function [DataBus]=import_excel(filename,sheets)
% Function to read excel sheets INFO
% Reads the data inside an Excel sheet by sheet and assigns to the output
%   value and orgaznize the structure the same way that is in excel, with the sheet name as the
%   first field name of the structure, then the first and second collumns
% The function contatins 2 exceptions: 'Info' and hardpoint sheets (specific for this application)
% Can be used with or without the sheets argument
% - [DataBus]=import_excel(filename) -> goes through all the sheets in a
%       file and creates a struct containing all sheets 
% - [DataBus]=import_excel(filename,sheets) -> goes through the specified
%       sheets 
% Specific features
% - the 'Value' field from excel supports multiple formats
    % - scalar
    % - vector - must be specified within square brackets (eg:[1 2 3])
    % - table - must be specified in 'Comments' field that the value is a
    %           table "TABLE", and there must exist a sheet with the same name as the value
    % - sheet - must be specified in 'Unit' that the value is a sheet, "SHEET", and there must 
    %           exist a sheet with the same name as the value
%% Gets all sheet names if sheet to read is not specified
if nargin == 1 || isempty(sheets)
    sheets = sheetnames(filename);
    ref=0;
else
    ref=1;
end
sheets = string(sheets);

%% Ignore hardpoint and Info sheets
if nargin == 1 & ~isempty(sheets(sheets=='HardpointsFr'))
   sheets= setdiff(sheets,'HardpointsFr');
end
if nargin == 1 & ~isempty(sheets(sheets=='HardpointsRr'))
    sheets= setdiff(sheets,'HardpointsRr');
end
if nargin == 1 & ~isempty(sheets(sheets=='Info'))
    sheets= setdiff(sheets,'Info');
end
if nargin == 1 & ~isempty(sheets(sheets=='TrqSpd'))
    sheets= setdiff(sheets,'TrqSpd');
end
%% Initializizations
DataBus=struct();
if nargin == 1
    referencedSheets = string([]);
    
    %% Get list of sheets that are referenced to ignore when reading
    for s = 1:numel(sheets)
        currentSheet = sheets{s};
        opts = detectImportOptions(filename, 'Sheet', currentSheet);
        opts.VariableNames = ["Var1", "Var2", "Var3", "Var4", "Var5"];
        opts = setvartype(opts, opts.VariableNames, 'string');
        opts = setvaropts(opts, opts.VariableNames, 'FillValue', "");
        sheetData = readtable(filename, opts);
    
        % Collect sheets referenced as 'SHEET'
        referencedSheets = [referencedSheets; sheetData.Var3(sheetData.Var4 == "SHEET")];
        referencedSheets = [referencedSheets; sheetData.Var3(sheetData.Var5 == "TABLE")];
    end
    
    % ✅ Clean referenced list
    referencedSheets = unique(strtrim(referencedSheets));
    referencedSheets = referencedSheets(referencedSheets ~= "");
    referencedSheets = rmmissing(referencedSheets);
    
    % ✅ Remove them from the main list
    sheets = setdiff(sheets, referencedSheets);
end
%% Reading sheets
for subsystem=1:length(sheets)

    % Read the current sheet type, instance and class 
    currentSheet = sheets{subsystem};
    type = readtable(filename, 'Sheet', currentSheet, 'Range', 'A1:E4');
    field = type{:,1};
    
    % Write type, instance, class in DataBus struct
    for i=1:length(field)
            if ~ismissing(type{i,3})  % Check if there is a value for the type and it's not empty
            DataBus.(currentSheet).(field{i}).Value = cell2mat(type{i,3});
            end

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

    %% Add data from sheet to DataBus struct
    for i=1:size(sheetData,1)
    
        % Recursive way to read struct inside structs
        if strcmp(sheetData.Var4{i},'SHEET')
            try
                DataBus.(currentSheet).(sheetData.Var1{i}) = import_excel(filename, sheetData.Var3{i});
            catch ME
                 error('File "%s" sheet name specified in "%s" row "%d" cannot be found: %s', filename, currentSheet, i, ME);
            end
        elseif strcmp(sheetData.Var5{i},'TABLE')
            % Read the table data and store it in the DataBus struct
            try
                tableData = readmatrix(filename,'Sheet',sheetData.Var3{i}); 
                DataBus.(currentSheet).(sheetData.Var1{i}).(sheetData.Var2{i}) = ...
                struct('Value',tableData,'Unit',sheetData.Var4(i),'Comments',sheetData.Var5(i));
            catch ME
                error('File "%s" table name specified in "%s" row "%d" cannot be found: %s',filename ,currentSheet, i, ME);
            end


        else
            %% Checks for patterns (vector values and 'do not change' comment)
            val = sheetData.Var3{i};
        
            if isstring(val) || ischar(val)
                txt = strtrim(val);   % remove leading/trailing spaces
        
            % Check for [ ... ] pattern
                if startsWith(txt, "[") && endsWith(txt, "]")
                    txt = extractBetween(txt, "[", "]");  % get inner text
                    txt = strrep(txt, ",", ".");          % replace commas with dots for safety
                    val = str2num(txt);
                elseif isempty(str2num(val))                 
                    val = strtrim(txt); % Ensure any leading/trailing spaces are removed
                else
                    val = str2num(txt);
                end
            
            
            % Avoids excel comment for hardpoints
                if contains(txt,'DO NOT CHANGE HERE')
                    erase(txt,'( DO NOT CHANGE HERE )');
                    val = txt;
                end

            end
            clear txt;

            %% Add contents to DataBus

            if strcmp(sheetData.Var2{i},'class')
                %% if clause to allow for small structures without additional sheets (only class value)

                DataBus.(currentSheet).(sheetData.Var1{i}).(sheetData.Var2{i}) = ...
                struct('Value',val);
            elseif strcmp(sheetData.Var1{i},'class')
                %% if clause to allow for small structures without additional sheets (only class value)

                DataBus.(currentSheet).(sheetData.Var1{i}) = ...
                struct('Value',val);
            elseif isempty(sheetData.Var2{i})
                
                DataBus.(currentSheet).(sheetData.Var1{i}) = ...
                struct('Value',val,'Unit',sheetData.Var4(i),'Comments',sheetData.Var5(i));
            else
                 %% Normal allocation of structures

            DataBus.(currentSheet).(sheetData.Var1{i}).(sheetData.Var2{i}) = ...
                struct('Value',val,'Unit',sheetData.Var4(i),'Comments',sheetData.Var5(i));
            end
            
            
        end
    end
    if ref==1
       DataBus = DataBus.(currentSheet);
    end
end
end

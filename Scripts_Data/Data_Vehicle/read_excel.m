function [data] = read_excel(workbookFile, sheetName, varargin)
     
    selectedVars=[];
    useRowNames=false;

    p = inputParser;
    addOptional(p, 'SelectedVar', selectedVars);
    addParameter(p, 'UseRowNames', useRowNames);
    parse(p, varargin{:});
    
    % Extract values
    selectedVars = p.Results.SelectedVar;
    useRowNames = p.Results.UseRowNames;

    % Detect import options
    opts = detectImportOptions(workbookFile, 'Sheet', sheetName);
   
    % If varName is provided and not empty, select specific variables
    if ~isempty(selectedVars)
        opts.SelectedVariableNames = selectedVars;
    end
    % Specify missing data handling
    opts.MissingRule = "omitrow";

    % Import the data
    data = readtable(workbookFile, opts);  
    if  useRowNames
        data.Properties.RowNames=data{:,1};
        data(:,1)=[];
    end
end

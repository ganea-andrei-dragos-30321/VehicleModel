function cost = customFISCost(fis)
    % Write FIS to file
    fisPath = 'FIS.fis';
    writeFIS(fis, fisPath);

    % Update block (adjust the block path!)
    fis=readfis(fisPath);
    % Simulate model
simOut = sim('sm_car','SaveOutput', 'on');

    % Extract trajectory signals from logsout
    actualTrajectory.X = simOut.logsout_sm_car{5}.Values.World.x.Data;    % Nx2 [X Y]
    actualTrajectory.Y = simOut.logsout_sm_car{5}.Values.World.y.Data;
    referenceTrajectory.X =reshape(simOut.logsout_sm_car{2}.Values.Reference.y.Data,[length(simOut.logsout_sm_car{2}.Values.Reference.y.Data) 1 1]); % Nx2 [X Y]
    referenceTrajectory.Y =reshape(simOut.logsout_sm_car{2}.Values.Reference.y.Data,[length(simOut.logsout_sm_car{2}.Values.Reference.y.Data) 1 1]) ; % Nx2 [X Y]

    % Get X and Y
    xErr = referenceTrajectory.X - actualTrajectory.X;
    yErr = referenceTrajectory.Y - actualTrajectory.Y;

    % Euclidean trajectory error
    euclideanError = sqrt(xErr.^2 + yErr.^2);

    % Cost: RMSE or total trajectory deviation
    cost = mean(euclideanError);  % or sum(euclideanError.^2);
end

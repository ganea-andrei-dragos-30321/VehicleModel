function CorrState = UKF(ukf, yMeas, u)

predict(ukf,u);
% Predict what the sensors should read based on the predicted state
    yPred = measurement_model(ukf.State, u);
    
    % Calculate the raw errors for COG (index 2) and Phi (index 3)
    raw_error_COG = yMeas(2) - yPred(2);
    raw_error_Phi = yMeas(3) - yPred(3);
    
    % Wrap the errors to be strictly between -pi and pi
    wrapped_error_COG = atan2(sin(raw_error_COG), cos(raw_error_COG));
    wrapped_error_Phi = atan2(sin(raw_error_Phi), cos(raw_error_Phi));
    
    % Construct a modified measurement vector. 
    % When the UKF does (yMeas_mod - yPred) internally, it will get the wrapped_error!
    yMeas_mod    = yMeas; % Copy original measurements
    yMeas_mod(2) = yPred(2) + wrapped_error_COG;
    yMeas_mod(3) = yPred(3) + wrapped_error_Phi;
    % --------------------------------
    
vx_safe = max(abs(ukf.State(1)), 1e-3);
if vx_safe < 2.0
    R_cog = single(1e6);
else
    R_cog = single((0.01/vx_safe)^2);
end
ukf.MeasurementNoise = single(diag([1e-3, R_cog, 5e-4, 1e-4, 1e-2, 1e-2]));
CorrState = correct(ukf,yMeas_mod,u);
CorrState(2) = atan2(sin(ukf.State(2)),cos(ukf.State(2)));
CorrState(3) = atan2(sin(ukf.State(3)),cos(ukf.State(3)));

if CorrState(1) < 0.1
    % If the corrected state is below a threshold, set it to zero
    CorrState(1) = max(CorrState(1), 0);
    CorrState(4) = 0;
    CorrState(2) = 0;

end
%ukf.StateCovariance = ukf.StateCovariance + 1e-6*eye(6);

end



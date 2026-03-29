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
    
ukf.State(2) = mod(ukf.State(2) + pi, 2*pi) - pi;

% If beta somehow flipped to the back of the car, force it to the front
if ukf.State(2) > pi/2
    ukf.State(2) = ukf.State(2) - pi;
elseif ukf.State(2) < -pi/2
    ukf.State(2) = ukf.State(2) + pi;
end
vx_safe = max(abs(ukf.State(1)), 1e-3);
ukf.MeasurementNoise = single(diag([1e-3, (0.01 / vx_safe)^2, 5e-4, 3e-3, 1e-2, 1e-2]));
CorrState = correct(ukf,yMeas_mod,u);
end

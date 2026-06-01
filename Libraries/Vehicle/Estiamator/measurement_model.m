function [y, wrapping] = measurement_model(x, u)
% y = [ V_GPS VOG Phi Phi_dotg a_xa a_ya omega_fl omega_fr ]
% u = [ delta,omega_fl, omega_fr, omega_rl, omega_rr ]
%#codegen
v_x     = x(1);
v_y     = x(2);
Phi     = x(3);
Phi_dot = x(4);
a_x     = x(5);
a_y     = x(6);



Params = get_vehicle_params();

%v_y = v_x * tan(beta);

% 4. GPS velocity
V_GPS = sqrt(v_x ^ 2 + (v_y + Phi_dot * Params.GPS.Lant) ^ 2);

eps = single(1e-3);


% 5. GPS course over ground
COG = Phi + atan2(v_y + Phi_dot * Params.GPS.Lant, v_x + eps);
 
% 6. Output Vector
% Must match the order of your MeasurementNoise (R) matrix
y = [V_GPS; COG; Phi; Phi_dot; a_x + Phi_dot*Phi_dot * 0.132; a_y];
y(2) = atan2(sin(y(2)),cos(y(2)));
y(3) = atan2(sin(y(3)),cos(y(3)));

infVal = cast(inf, 'like', y);
piVal  = cast(pi,  'like', y);

wrapping = [ ...
    -infVal,  infVal;  % V_GPS not wrapped
    -piVal,   piVal;   % COG wrapped
    -piVal,   piVal;   % Phi/yaw wrapped
    -infVal,  infVal;  % yaw rate not wrapped
    -infVal,  infVal;  % ax not wrapped
    -infVal,  infVal]; % ay not wrapped
end

function y = measurement_model(x, u)
% y = [ V_GPS VOG Phi Phi_dotg a_xa a_ya omega_fl omega_fr ]
% u = [ delta,omega_fl, omega_fr, omega_rl, omega_rr ]
%#codegen
v_x     = x(1);
v_y    = x(2);
Phi     = x(3);
Phi_dot = x(4);
a_x     = x(5);
a_y     = x(6);



Params = get_vehicle_params();

eps = single(3e-1);

if abs(v_x) < 0.3
    v_x = eps;
end

%v_y = v_x * tan(beta);

% 4. GPS velocity
V_GPS = sqrt(v_x ^ 2 + (v_y + Phi_dot * Params.GPS.Lant) ^ 2);

% 5. GPS course over ground
COG = Phi + atan2(v_y + Phi_dot * Params.GPS.Lant, v_x);
 
% 6. Output Vector
% Must match the order of your MeasurementNoise (R) matrix
y = [V_GPS; COG; Phi; Phi_dot; a_x; a_y];
end
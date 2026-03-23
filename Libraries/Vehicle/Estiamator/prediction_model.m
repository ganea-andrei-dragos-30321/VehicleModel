function x_next = prediction_model(x, u)
%#codegen
% u     = [ delta  omega_fl omega_fr omega_rl omega_rr ]
% x     = [ v_x v_y Phi Phi_dot a_x a_y miu ]
% x_dot = [ v_x_dot v_y_dot Phi_dot a_x_dot a_y_dot]
v_x      = x(1);
beta     = x(2);
Phi      = x(3);
Phi_dot  = x(4);
a_x      = x(5);
a_y      = x(6);


delta    = u(1) / 7;
omega_fl = u(2); % Front left wheel angular velocity
omega_fr = u(3); % Front right wheel angular velocity
omega_rl = u(4); % Rear left wheel angular velocity
omega_rr = u(5); % Rear right wheel angular velocity

Params = get_vehicle_params();
eps = single(1e-1);

if abs(v_x) < 0.1
    v_x = eps;
end

v_y = v_x * tan(beta);

% Aero forces
Fz_down     = 1 / 2 * Params.Physics.ro * Params.Car.Af * Params.Car.cl * v_x ^ 2;
Fx_drag     = 1 / 2 * Params.Physics.ro * Params.Car.Af * Params.Car.cd * v_x ^ 2;

% Ackerman steering angles
delta_L     = atan(Params.Car.L / (Params.Car.L / tan(delta) - Params.Car.tf / 2));
delta_R     = atan(Params.Car.L / (Params.Car.L / tan(delta) + Params.Car.tf / 2));

% Slip angles
alpha_fl    = atan((v_y + Phi_dot * Params.Car.a) / (v_x - Phi_dot * Params.Car.tf / 2)) - delta_L;
alpha_fr    = atan((v_y + Phi_dot * Params.Car.a) / (v_x + Phi_dot * Params.Car.tf / 2)) - delta_R;
alpha_rl    = atan((v_y - Phi_dot * Params.Car.b) / (v_x - Phi_dot * Params.Car.tr / 2));
alpha_rr    = atan((v_y - Phi_dot * Params.Car.b) / (v_x + Phi_dot * Params.Car.tr / 2));

% Slip ratios
kappa_fl    = (omega_fl * Params.Tire.r_load - (v_x - Phi_dot * Params.Car.tf / 2) * cos(alpha_fl)) / max(omega_fl * Params.Tire.r_load, (v_x - Phi_dot * Params.Car.tf / 2) * cos(alpha_fl));
kappa_fr    = (omega_fr * Params.Tire.r_load - (v_x + Phi_dot * Params.Car.tf / 2) * cos(alpha_fr)) / max(omega_fr * Params.Tire.r_load, (v_x + Phi_dot * Params.Car.tf / 2) * cos(alpha_fr));
kappa_rl    = (omega_rl * Params.Tire.r_load - (v_x - Phi_dot * Params.Car.tr / 2) * cos(alpha_rl)) / max(omega_rl * Params.Tire.r_load, (v_x - Phi_dot * Params.Car.tr / 2) * cos(alpha_rl));
kappa_rr    = (omega_rr * Params.Tire.r_load - (v_x + Phi_dot * Params.Car.tr / 2) * cos(alpha_rr)) / max(omega_rr * Params.Tire.r_load, (v_x + Phi_dot * Params.Car.tr / 2) * cos(alpha_rr));

% Wheel loads 
Fz_fl       = Params.Car.m * Params.Physics.g * Params.Car.b / Params.Car.L - Fz_down * Params.Car.b_cop / Params.Car.L - 1 / 2 * Params.Car.m * a_x * Params.Car.h_cog / Params.Car.L - 1 / 2 * Params.Car.m * a_y * Params.Car.h_cog / Params.Car.tf;
Fz_fr       = Params.Car.m * Params.Physics.g * Params.Car.b / Params.Car.L - Fz_down * Params.Car.b_cop / Params.Car.L - 1 / 2 * Params.Car.m * a_x * Params.Car.h_cog / Params.Car.L + 1 / 2 * Params.Car.m * a_y * Params.Car.h_cog / Params.Car.tf;
Fz_rl       = Params.Car.m * Params.Physics.g * Params.Car.a / Params.Car.L - Fz_down * Params.Car.a_cop / Params.Car.L + 1 / 2 * Params.Car.m * a_x * Params.Car.h_cog / Params.Car.L - 1 / 2 * Params.Car.m * a_y * Params.Car.h_cog / Params.Car.tr;
Fz_rr       = Params.Car.m * Params.Physics.g * Params.Car.a / Params.Car.L - Fz_down * Params.Car.a_cop / Params.Car.L + 1 / 2 * Params.Car.m * a_x * Params.Car.h_cog / Params.Car.L + 1 / 2 * Params.Car.m * a_y * Params.Car.h_cog / Params.Car.tr;

% Magic formula lateral 
Fy_fl       = MF_y(Fz_fl, alpha_fl, kappa_fl, Params.Tire.lat);
Fy_fr       = MF_y(Fz_fr, alpha_fr, kappa_fr, Params.Tire.lat);
Fy_rl       = MF_y(Fz_rl, alpha_rl, kappa_rl, Params.Tire.lat);
Fy_rr       = MF_y(Fz_rr, alpha_rr, kappa_rr, Params.Tire.lat);

% Magic formula longitudinal 
Fx_fl       = MF_x(Fz_fl, alpha_fl, kappa_fl, Params.Tire.long);
Fx_fr       = MF_x(Fz_fr, alpha_fr, kappa_fr, Params.Tire.long);
Fx_rl       = MF_x(Fz_rl, alpha_rl, kappa_rl, Params.Tire.long);
Fx_rr       = MF_x(Fz_rr, alpha_rr, kappa_rr, Params.Tire.long);

% State derivatives [1, 2, 4]
v_x_dot     = 1 / Params.Car.m * (Fx_rr + Fx_rl + Fx_fl * cos(delta_L) + Fx_fr * cos(delta_R) - Fy_fl * sin(delta_L) - Fy_fr * sin(delta_R) + Fx_drag) + v_y * Phi_dot;
v_y_dot     = 1 / Params.Car.m * (Fy_rr + Fy_rl + Fx_fl * sin(delta_L) + Fx_fr * sin(delta_R) + Fy_fl * cos(delta_L) + Fy_fr * cos(delta_R)) - v_x * Phi_dot;
Phi_dot_dot = 1 / Params.Car.Izz * ((Fy_fl * cos(delta_L) + Fx_fl * sin(delta_L) + Fx_fr * sin(delta_R) + Fy_fr * cos(delta_R)) * Params.Car.a - Fy_rl * Params.Car.b - Fy_rr * Params.Car.b + (Fx_rr - Fx_rl) * Params.Car.tr / 2 + (Fx_fr*cos(delta_R) - Fy_fr * sin(delta_R) + Fy_fl * sin(delta_L) - Fx_fl*cos(delta_L))*Params.Car.tf/2);

v_safe_sq = max(v_x^2 + v_y^2, single(0.1)); 
beta_dot  = (v_y_dot * v_x - v_y * v_x_dot) / v_safe_sq;
% Random walk model (assume 0 jerk with exception of some noise) [4, 5, 6]
a_x_dot  = 0;
a_y_dot  = 0;

x_dot    = [v_x_dot, beta_dot, Phi_dot, Phi_dot_dot, a_x_dot, a_y_dot]';

% Update state using Euler integration
x_next   = x + x_dot * Params.TimeStep; 
end
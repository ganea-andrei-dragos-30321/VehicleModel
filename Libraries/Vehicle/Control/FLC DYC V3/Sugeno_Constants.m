%% ============================================================
%  Offline LQR gain computation for first-order Sugeno FLC
%  States: [vx, vy, Phi, Phi_dot, ax, ay]
%  Operating point dims: Vx, delta, e_phi, e_beta
%% ============================================================
C_alpha_f = 1.7e4 * 2;   % front cornering stiffness [N/rad]
C_alpha_r = 3.1e4 * 2;   % rear cornering stiffness [N/rad]

Params    = get_vehicle_params();
K_us      = Params.Car.m / (2 * Params.Car.L) * (Params.Car.a / C_alpha_f - Params.Car.b / C_alpha_r); 
%% --- Operating point grids (MF centres) ----------------------
Vx_ops    = [5,  12,  17.5];          % m/s      → Low, Mid, High
delta_ops = [-0.38, -0.15, 0, 0.15, 0.38]; % rad front wheel → NL,NS,ZE,PS,PL
ephi_ops  = [-1.0, -0.5, 0, 0.5, 1.0];     % rad/s → NL,NS,ZE,PS,PL
ebeta_ops = [-0.15, 0, 0.15];              % rad   → N, ZE, P

%% --- Bryson weights ------------------------------------------
ephi_max  = 1.2;     % rad/s
dMz_max   = 650;    % Nm

Q = 1/ephi_max^2;
R = 1 / dMz_max^2;

%% --- Storage -------------------------------------------------
% Columns: [Vx, delta, e_phi, e_beta, k_beta, Iz_lambda]
results = zeros(numel(Vx_ops)*numel(delta_ops)* ...
                numel(ephi_ops)*numel(ebeta_ops), 6);
row = 1;

%% --- Main loop ----------------------------------------------
for i = 1:numel(Vx_ops)
  for j = 1:numel(delta_ops)
    for k = 1:numel(ephi_ops)
      for l = 1:numel(ebeta_ops)

        Vx    = Vx_ops(i);
        delta = delta_ops(j);          % front wheel angle [rad]
        e_phi = ephi_ops(k);           % yaw rate error [rad/s]
        e_beta= ebeta_ops(l);          % sideslip error [rad]

        %% --- Reference values --------------------------------
        phi_ref  = (Vx * delta) / ...
                   (Params.Car.L * (1 + K_us * Vx^2));

        beta_ref = ((Params.Car.b - ...
                     Params.Car.a * Params.Car.m * Vx^2 / ...
                     (2 * Params.Car.L * C_alpha_f)) / ...
                    (Params.Car.L + K_us * Vx^2)) * delta;

        %% --- Actual states at this operating point -----------
        % e_phi  = phi_ref  - phi_actual  → phi_actual  = phi_ref  - e_phi
        % e_beta = beta_ref - beta_actual → beta_actual = beta_ref - e_beta
        phi_actual  = phi_ref  - e_phi;
        beta_actual = beta_ref - e_beta;

        % Lateral velocity from sideslip definition
        vy_actual   = Vx * tan(beta_actual);

        % Approximate accelerations
        ay_approx   = phi_actual * Vx;   % centripetal
        ax_approx   = 0;

        %% --- Build state and input vectors -------------------
        x0 = [Vx;
               vy_actual;
               0;                         % Phi — irrelevant for linearization
               phi_actual;
               ax_approx;
               ay_approx];

        omega_nom = Vx / Params.Car.r_load;
        u0 = [delta * Params.Car.SteerR;  % back to steering wheel angle
              omega_nom;
              omega_nom;
              omega_nom;
              omega_nom];

        %% --- Numerical Jacobian ------------------------------
        [A_full, B_full] = continuous_jacobian(x0, u0, Params);

        % Reduce to [vy(2), Phi_dot(4)] — our controlled states
        % vy maps to beta via beta = atan(vy/vx) ≈ vy/vx
        idx   =  4;
        A_red = A_full(idx, idx);
        B_red = B_full(idx);
        sv = svd(ctrb(A_red,B_red));
        %% --- LQR solve --------------------------------------
        try
          K_lqr = lqr(A_red, B_red, Q, R);
        catch
          warning('LQR failed: Vx=%.0f delta=%.2f ephi=%.1f ebeta=%.2f', ...
                   Vx, delta, e_phi, e_beta);
          row = row + 1;
          continue
        end

        % K_lqr = [k_vy,  k_phidot]
        % Convert k_vy → k_beta:  beta ≈ vy/Vx  →  k_beta = k_vy * Vx
        Iz_lambda  = K_lqr;     % = Iz * lambda
        coupling  = A_full(4, 2);    % ∂φ̈/∂vy — how much vy affects yaw
        k_beta_val = Iz_lambda * abs(coupling) * Vx * 1e-3;
        if abs(Iz_lambda) > 5000 || abs(k_beta_val) > 5000
             warning('Gain out of bounds at Vx=%.0f delta=%.2f: Iz_lam=%.0f k_b=%.0f', ...
             Vx, delta, Iz_lambda, k_beta_val);
             % Fall back to nearest neighbour in post-processing
              k_beta_val = 0;
              Iz_lambda  = 0;
        end
        results(row,:) = [Vx, delta, e_phi, e_beta, k_beta_val, Iz_lambda];
        row = row + 1;

      end
    end
  end
end

results = results(1:row-1, :);  % trim unused rows

%% --- Inspect gain surfaces ----------------------------------
% Example: fix delta=0, e_beta=0, sweep Vx and e_phi
mask = results(:,3)==0 & results(:,4)==0;
sub  = results(mask,:);
FIS_Builder(sub(:,5:6))
figure;
subplot(1,2,1);
scatter(sub(:,1), sub(:,4), 60, sub(:,5), 'filled');
xlabel('Vx (m/s)'); ylabel('e\_\phi (rad/s)');
title('k\_\beta gain surface'); colorbar; grid on;

subplot(1,2,2);
scatter(sub(:,1), sub(:,3), 60, sub(:,6), 'filled');
xlabel('Vx (m/s)'); ylabel('e\_\phi (rad/s)');
title('Iz·\lambda gain surface'); colorbar; grid on;

%% --- Export singleton table for Sugeno FLC ------------------
% Each row = one rule's consequent coefficients
% ΔMz_i = Iz_lambda_i * e_phi + k_beta_i * e_beta
save('sugeno_singletons.mat', 'results', 'Params', 'K_us');
fprintf('Done. %d operating points computed.\n', row-1);

%% Jacobian Function
function [Ac, Bc] = continuous_jacobian(x0, u0, Params)
% prediction_model implements x_next = x + f(x,u)*dt
% Therefore: A_discrete = I + Ac*dt  →  Ac = (A_disc - I)/dt
%            B_discrete = Bc*dt      →  Bc = B_disc/dt

dt    = Params.TimeStep;
n     = length(x0);
f0    = prediction_model(x0, u0);
eps_x = 1e-6;

% Discrete A via finite differences
A_disc = zeros(n,n);
for i = 1:n
    xp         = x0;
    xp(i)      = xp(i) + eps_x;
    A_disc(:,i)= (prediction_model(xp, u0) - f0) / eps_x;
end

% Discrete B via direct ΔMz injection
eps_Mz = 1;
f_pert = dyc_inject(x0, u0, eps_Mz, Params);
B_disc = (f_pert - f0) / eps_Mz;

% Convert to continuous time
Ac = (A_disc - eye(n)) / dt;
Bc = B_disc / dt;

% % Sanity check — Bc(4) should be ≈ 1/Iz
% expected = 1 / Params.Car.Izz;
% actual   = Bc(4);
% if abs(actual - expected)/expected > 0.01
%     warning('Bc(4)=%.4e but 1/Iz=%.4e — check injection', actual, expected);
% end
 end
%% --- Wrapper that adds ΔMz directly to yaw acceleration ----
function x_next = dyc_inject(x, u, dMz, Params)
    x_next    = prediction_model(x, u);
    % ΔMz enters as additional yaw moment → adds to Phi_dot state
    x_next(4) = x_next(4) + (dMz / Params.Car.Izz);
end
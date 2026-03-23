function Params = get_vehicle_params()
%#codegen
% Physical parameters
Params.Physics.g              = 9.81;               % Gravitational acceleration [m/s^2]
Params.Physics.ro             = 1.225;              % Air density [kg/m^3]

% Ecu parameters
Params.TimeStep               = 0.005;               % Time step for integration

% GPS postion 
Params.GPS.Lant               = 0.874;                  % Distance from front antenna to the CoG [m]

% Vehicle parmeters
Params.Car.a           = 0.874;         % Distance from CoG to front axle[ m]
Params.Car.b           = 0.701;         % Distance from CoG to rear axle [m]
Params.Car.tf          = 1.3;         % Front track [m]
Params.Car.tr          = 1.28;         % Rear track [m]
Params.Car.m           = 280;       % Mass [kg]
Params.Car.L           = 1.575;     % Wheelbase
Params.Car.b_cop       = 0.775;         % Distance from center of pressure to rear axle [m]
Params.Car.a_cop       = 0.8;         % Distance from center of pressure to front axle [m]
Params.Car.h_cog       = 0.34;         % CoG height [m]
Params.Car.Izz         = 170;         % Yaw inertia [kg*m^2]
Params.Car.Af          = 1.2;       % Frontal area [m^2]
Params.Car.cl          = -2.15;       % Lift coefficient [~]
Params.Car.cd          = -1;       % Drag coefficient [~]

% TIRE 
% General parameters
Params.Tire.f          = 0.02;      % Rolling resistance coef [~]
Params.Tire.r_load     = 0.257;     % Load tire radius [m]

% Tire model parameters
% --- Essential Longitudinal Parameters ---
Params.Tire.long.Fz0   = 1112;      % Nominal load
Params.Tire.long.LFZ0  = 1;         % Scale factor load
Params.Tire.long.LMUX  = 1;         % Peak friction scale
Params.Tire.long.LCX   = 1;         % Shape factor scale
Params.Tire.long.LEX   = 1;         % Curvature factor scale
Params.Tire.long.LKX   = 1;         % Stiffness scale
Params.Tire.long.LHX   = 1;         % Horizontal shift scale
Params.Tire.long.LVX   = 1;         % Vertical shift scale
Params.Tire.long.LXAL  = 1;         % Combined stiffness scale

% Pure Longitudinal Coefs
Params.Tire.long.PCX1  = 1.35825;   % Shape factor Cfx
Params.Tire.long.PDX1  = 2.35273;   % Friction Mux at Fznom
Params.Tire.long.PDX2  = -0.08098;  % Friction variation with load
Params.Tire.long.PEX1  = -0.97676;  % Curvature Efx at Fznom
Params.Tire.long.PEX2  = -0.42592;  % Curvature variation with load
Params.Tire.long.PEX3  = 3.34645;   % Curvature variation with load squared
Params.Tire.long.PEX4  = -0.35633;  % Asymmetry factor (driving vs braking)
Params.Tire.long.PKX1  = 55.374;    % Slip stiffness Kfx/Fz at Fznom
Params.Tire.long.PKX2  = 15.258;    % Stiffness variation with load
Params.Tire.long.PKX3  = -0.49428;  % Stiffness exponent with load
Params.Tire.long.PHX1  = -0.00026;  % Horizontal shift Shx
Params.Tire.long.PHX2  = -0.0005;   % Shift variation with load
Params.Tire.long.PVX1  = 0.02483;   % Vertical shift Svx/Fz
Params.Tire.long.PVX2  = -0.03475;  % Shift variation with load

% Combined Slip Coefs
Params.Tire.long.RBX1  = 63.893;    % Slope factor
Params.Tire.long.RBX2  = 6.3955;     % Slope variation with kappa
Params.Tire.long.RCX1  = 1.47276;   % Shape factor
Params.Tire.long.REX1  = 0.99625;   % Curvature factor
Params.Tire.long.REX2  = 3e-05;     % Curvature variation with load
Params.Tire.long.RHX1  = 0.89759;   % Shift factor

% --- Essential Lateral Parameters ---
Params.Tire.lat.Fz0   = 1112;      % Nominal load
Params.Tire.lat.LCY   = 1;         % Shape factor scale
Params.Tire.lat.LEY   = 1;         % Curvature factor scale
Params.Tire.lat.LKY   = 1;         % Cornering stiffness scale
Params.Tire.lat.LHY   = 1;         % Horizontal shift scale
Params.Tire.lat.LVY   = 1;         % Vertical shift scale
Params.Tire.lat.LYKA  = 1;         % Kappa influence scale
Params.Tire.lat.LVYKA = 1;         % Kappa induced Fy scale
Params.Tire.lat.LMUY  = 1;         % Peak friction scale
Params.Tire.lat.LFZ0  = 1;         % Scale factor load

% Pure Lateral Coefs
Params.Tire.lat.PCY1  = 1.51563;   % Shape factor Cfy
Params.Tire.lat.PDY1  = 2.26717;   % Lateral friction Muy
Params.Tire.lat.PDY2  = -0.29707;  % Friction variation with load
Params.Tire.lat.PEY1  = 0.24545;   % Curvature Efy
Params.Tire.lat.PEY2  = -0.01941;  % Curvature variation with load
Params.Tire.lat.PKY1  = -58.654;   % Max stiffness Kfy/Fznom
Params.Tire.lat.PKY2  = 3.70898;   % Load for max stiffness
Params.Tire.lat.PKY4  = 3.67515;   % Curvature of stiffness
Params.Tire.lat.PHY1  = 0.00435;   % Horizontal shift Shy
Params.Tire.lat.PHY2  = 0.00331;   % Shift variation with load
Params.Tire.lat.PVY1  = 0.02353;   % Vertical shift Svy
Params.Tire.lat.PVY2  = 0.01157;   % Shift variation with load

% Combined Slip Coefs
Params.Tire.lat.RBY1  = 12.784;    % Slope factor
Params.Tire.lat.RBY2  = 23.08;     % Slope variation with alpha
Params.Tire.lat.RBY3  = 0.02841;   % Alpha shift
Params.Tire.lat.RCY1  = 0.85547;   % Shape factor
Params.Tire.lat.REY1  = -4.28658;  % Curvature factor
Params.Tire.lat.REY2  = 3.32351;   % Curvature variation with load
Params.Tire.lat.RHY1  = 0.006;     % Shift factor
Params.Tire.lat.RHY2  = 0.02348;   % Shift variation with load
Params.Tire.lat.RVY1  = -0.02376;  % Kappa induced side force
Params.Tire.lat.RVY2  = -0.03991;  % variation with load
Params.Tire.lat.RVY4  = 0.02379;   % variation with alpha
Params.Tire.lat.RVY5  = 1.99981;   % variation with kappa
Params.Tire.lat.RVY6  = 17.525;    % variation with atan(kappa)

end
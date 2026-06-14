function Params = get_vehicle_params()
%#codegen
% Physical parameters
Params.Physics.g              = 9.81;               % Gravitational acceleration [m/s^2]
Params.Physics.ro             = 1.225;              % Air density [kg/m^3]

% Ecu parameters
Params.TimeStep               = 0.003;              % Time step for integration

% GPS postion 
Params.GPS.Lant               = 0.6812;              % Distance from front antenna to the CoG [m]

% Vehicle parmeters
Params.Car.SteerR      = 5.71;      % Steering Ratio 
Params.Car.a           = 0.8232;     % Distance from CoG to front axle[ m]
Params.Car.b           = 0.7518;     % Distance from CoG to rear axle [m]
Params.Car.tf          = 1.28;      % Front track [m]
Params.Car.tr          = 1.25;      % Rear track [m]
Params.Car.m           = 315;       % Mass [kg]
Params.Car.L           = 1.578;     % Wheelbase
Params.Car.b_cop       = 0.868;     % Distance from center of pressure to rear axle [m]
Params.Car.a_cop       = 0.707;       % Distance from center of pressure to front axle [m]
Params.Car.h_cog       = 0.3583;      % CoG height [m]
Params.Car.Izz         = 140;       % Yaw inertia [kg*m^2]
Params.Car.Af          = 1.2;       % Frontal area [m^2]
Params.Car.cl          = -2.15;     % Lift coefficient [~] -0.9
Params.Car.cd          = -1;        % Drag coefficient [~] -0.8
% General tire parameters
Params.Car.f          = 0.02;      % Rolling resistance coef [~]
Params.Car.r_load     = 0.263;     % Load tire radius [m]
% =========================================================
% TIRE BUILDER
% Build the BaseTire first to prevent MATLAB Coder errors
% =========================================================


% --- Essential Longitudinal Parameters ---
BaseTire.long.Fz0   = 1112;      % Nominal load
BaseTire.long.LFZ0  = 1;         % Scale factor load
BaseTire.long.LMUX  = 1;         % Peak friction scale
BaseTire.long.LCX   = 1;         % Shape factor scale
BaseTire.long.LEX   = 1;         % Curvature factor scale
BaseTire.long.LKX   = 1;         % Stiffness scale
BaseTire.long.LHX   = 1;         % Horizontal shift scale
BaseTire.long.LVX   = 1;         % Vertical shift scale
BaseTire.long.LXAL  = 1;         % Combined stiffness scale

% Pure Longitudinal Coefs
BaseTire.long.PCX1  = 1.35825;   % Shape factor Cfx
BaseTire.long.PDX1  = 2.35273;   % Friction Mux at Fznom
BaseTire.long.PDX2  = -0.08098;  % Friction variation with load
BaseTire.long.PEX1  = -0.97676;  % Curvature Efx at Fznom
BaseTire.long.PEX2  = -0.42592;  % Curvature variation with load
BaseTire.long.PEX3  = 3.34645;   % Curvature variation with load squared
BaseTire.long.PEX4  = -0.35633;  % Asymmetry factor (driving vs braking)
BaseTire.long.PKX1  = 55.374;    % Slip stiffness Kfx/Fz at Fznom
BaseTire.long.PKX2  = 15.258;    % Stiffness variation with load
BaseTire.long.PKX3  = -0.49428;  % Stiffness exponent with load
BaseTire.long.PHX1  = -0.00026;  % Horizontal shift Shx
BaseTire.long.PHX2  = -0.0005;   % Shift variation with load
BaseTire.long.PVX1  = 0.02483;   % Vertical shift Svx/Fz
BaseTire.long.PVX2  = -0.03475;  % Shift variation with load

% Combined Slip Coefs
BaseTire.long.RBX1  = 63.893;    % Slope factor
BaseTire.long.RBX2  = 6.3955;    % Slope variation with kappa
BaseTire.long.RCX1  = 1.47276;   % Shape factor
BaseTire.long.REX1  = 0.99625;   % Curvature factor
BaseTire.long.REX2  = 3e-05;     % Curvature variation with load
BaseTire.long.RHX1  = 0.89759;   % Shift factor

% --- Essential Lateral Parameters ---
BaseTire.lat.Fz0   = 1112;      % Nominal load
BaseTire.lat.LCY   = 1;         % Shape factor scale
BaseTire.lat.LEY   = 1;         % Curvature factor scale
BaseTire.lat.LKY   = 1;         % Cornering stiffness scale
BaseTire.lat.LHY   = 1;         % Horizontal shift scale
BaseTire.lat.LVY   = 1;         % Vertical shift scale
BaseTire.lat.LYKA  = 1;         % Kappa influence scale
BaseTire.lat.LVYKA = 1;         % Kappa induced Fy scale
BaseTire.lat.LMUY  = 1;         % Peak friction scale
BaseTire.lat.LFZ0  = 1;         % Scale factor load

% Pure Lateral Coefs
BaseTire.lat.PCY1  = 1.51563;   % Shape factor Cfy
BaseTire.lat.PDY1  = 2.26717;   % Lateral friction Muy
BaseTire.lat.PDY2  = -0.29707;  % Friction variation with load
BaseTire.lat.PEY1  = 0.24545;   % Curvature Efy
BaseTire.lat.PEY2  = -0.01941;  % Curvature variation with load
BaseTire.lat.PKY1  = -58.654;   % Max stiffness Kfy/Fznom
BaseTire.lat.PKY2  = 3.70898;   % Load for max stiffness
BaseTire.lat.PKY4  = 3.67515;   % Curvature of stiffness
BaseTire.lat.PHY1  = 0.00435;   % Horizontal shift Shy
BaseTire.lat.PHY2  = 0.00331;   % Shift variation with load
BaseTire.lat.PVY1  = 0.02353;   % Vertical shift Svy
BaseTire.lat.PVY2  = 0.01157;   % Shift variation with load

% Combined Slip Coefs
BaseTire.lat.RBY1  = 12.784;    % Slope factor
BaseTire.lat.RBY2  = 23.08;     % Slope variation with alpha
BaseTire.lat.RBY3  = 0.02841;   % Alpha shift
BaseTire.lat.RCY1  = 0.85547;   % Shape factor
BaseTire.lat.REY1  = -4.28658;  % Curvature factor
BaseTire.lat.REY2  = 3.32351;   % Curvature variation with load
BaseTire.lat.RHY1  = 0.006;     % Shift factor
BaseTire.lat.RHY2  = 0.02348;   % Shift variation with load
BaseTire.lat.RVY1  = -0.02376;  % Kappa induced side force
BaseTire.lat.RVY2  = -0.03991;  % variation with load
BaseTire.lat.RVY4  = 0.02379;   % variation with alpha
BaseTire.lat.RVY5  = 1.99981;   % variation with kappa
BaseTire.lat.RVY6  = 17.525;    % variation with atan(kappa)

% =========================================================
% TIRE SPLITTER (Left/Right Assignment)
% =========================================================

% 1. Create Left and Right versions from the base
TireRight = BaseTire;
TireLeft  = BaseTire;

% 2. Invert lateral shifts for the Left tires (Conicity/Plysteer mirror)
TireLeft.lat.PHY1 = -BaseTire.lat.PHY1;
TireLeft.lat.PHY2 = -BaseTire.lat.PHY2;
TireLeft.lat.PVY1 = -BaseTire.lat.PVY1;
TireLeft.lat.PVY2 = -BaseTire.lat.PVY2;

% 3. Attach them cleanly to the main Params struct
Params.TireRight = TireRight;
Params.TireLeft  = TireLeft;

end
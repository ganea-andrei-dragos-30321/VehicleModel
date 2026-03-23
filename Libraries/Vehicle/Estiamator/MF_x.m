function Fx = MF_x(Fz, alpha, kappa, long)

%#codegen
coder.inline('always')

% Friction scalling coeficient
Amu = 1;
LMUX_prime = Amu * long.LMUX / (1 + (Amu - 1) * long.LMUX);  

% 1. Pure longitudinal
% Nominal load and normalized nominal load
Fz0 = long.Fz0;  
dfz = (Fz - long.LFZ0 * Fz0) / (long.LFZ0 * Fz0); 

% Longitudinal stiffness (Kx)
Kx = Fz * (long.PKX1 + long.PKX2 * dfz) * exp(long.PKX3 * dfz) * long.LKX;  

% Shift terms
SHx = (long.PHX1 + long.PHX2 * dfz) * long.LHX;
SVx = Fz * (long.PVX1 + long.PVX2 * dfz) * long.LVX * LMUX_prime;

% Slip ratio shift
kappax = kappa + SHx;

% Peak longitudinal Friction (mux), Force (Dx)
mux = (long.PDX1 + long.PDX2 * dfz) * long.LMUX;
Dx 	= mux * Fz;

% Shape (Cx), Curvature (Ex), Stiffness (Bx)
Cx 	= long.PCX1 * long.LCX;
if kappax >= 0
    Ex = (long.PEX1 + long.PEX2 * dfz + long.PEX3 * dfz^2) * (1 - long.PEX4) * long.LEX;
else
    Ex = (long.PEX1 + long.PEX2 * dfz + long.PEX3 * dfz^2) * (1 + long.PEX4) * long.LEX;
end
Bx = Kx / (Cx * Dx + 1e-6);

% Pure longitudinal force
Fx0 = Dx * sin(Cx * atan(Bx * kappax - Ex * (Bx * kappax - atan(Bx * kappax)))) + SVx;

% 2. Weighting function for combined slip
% Shift term
SHxa = long.RHX1;

% Shape (Cxa), Curvature (Exa), and Stiffness (Bxa)
Cxa = long.RCX1; 
Exa = long.REX1 + long.REX2 * dfz;
Bxa = long.RBX1 * cos(atan(long.RBX2 * kappa)) * long.LXAL;
            
% Weighting function term with alpha shift
alphas = alpha + SHxa;  
            
Gxa0 = cos(Cxa * atan(Bxa * SHxa - Exa * (Bxa * SHxa - atan(Bxa * SHxa))));  
Gxa = cos(Cxa * atan(Bxa * alphas - Exa * (Bxa * alphas - atan(Bxa * alphas)))) / Gxa0; 
            
% 3. Lateral force

Fx = Gxa * Fx0;
end
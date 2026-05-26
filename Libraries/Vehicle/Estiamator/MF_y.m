function Fy = MF_y(Fz_in, alpha, kappa, lat)
%#codegen
coder.inline('always')

% 1. PROTECT FZ: Prevent wheel lift-off and negative loads
% A minimum load of 10 Newtons keeps the math stable without affecting vehicle dynamics
Fz = max(Fz_in, single(10.0)); 

Amu = 1;
LMUY_prime = Amu * lat.LMUY / (1 + (Amu - 1) * lat.LMUY); 

% Nominal load and normalized nominal load
Fz0 = lat.Fz0;
dfz = (Fz - Fz0 * lat.LFZ0) / ( Fz0 * lat.LFZ0);

% Cornering Stiffness (Kya)
Ky = lat.PKY1 * Fz0 *sin(lat.PKY4 * atan((Fz / Fz0) / ((lat.PKY2 * lat.LFZ0))))* lat.LFZ0 * lat.LKY; 

% Shift terms
SHy = (lat.PHY1 + lat.PHY2 * dfz) * lat.LHY;
SVy = Fz * (lat.PVY1 + lat.PVY2 * dfz) * lat.LVY * LMUY_prime;

% Peak lateral Friction (muy) and Peak Force (Dy)
muy = (lat.PDY1 + lat.PDY2 * dfz) * lat.LMUY; 
Dy = muy * Fz; 

% Shape (Cy), Curvature (Ey), and Stiffness (By)
Cy = lat.PCY1 * lat.LCY;  
Ey = (lat.PEY1 + lat.PEY2 * dfz) * lat.LEY;    

% 2. PROTECT By: Prevent -1e-6 cancellation
By = Ky / max(Cy * Dy, single(1e-4)); 

% Pure lateral slip with slip angle shift
alphay = alpha + SHy; 
Fy0 = Dy * sin(Cy * atan(By * alphay - Ey *(By * alphay - atan(By * alphay))))+ SVy;

% Weighting function for combined slip
SHyk = lat.RHY1 + lat.RHY2 * dfz; 
Cyk = lat.RCY1;
Eyk = lat.REY1 + lat.REY2 * dfz;
Byk = lat.RBY1 * cos(atan(lat.RBY2 * (alpha - lat.RBY3))) * lat.LYKA;

kappas = kappa + SHyk; 
            
Gyk0 = cos(Cyk * atan(Byk * SHyk - Eyk * (Byk * SHyk - atan(Byk * SHyk)))); 

% 3. PROTECT Gyk: Prevent division by zero
Gyk0_safe = sign(Gyk0) * max(abs(Gyk0), single(1e-4));
if Gyk0_safe == 0 % Fallback just in case sign is 0
    Gyk0_safe = single(1e-4);
end

Gyk = cos(Cyk * atan(Byk * kappas - Eyk *(Byk * kappas - atan(Byk * kappas)))) / Gyk0_safe; 

% Kappa induced peak force (DVyk) and kappa induced side force (SVyk)
DVyk = muy * Fz * (lat.RVY1 + lat.RVY2 * dfz) * cos(atan(lat.RVY4 * alpha));  
SVyk = DVyk * sin(lat.RVY5 * atan(lat.RVY6 * kappa)) * lat.LVYKA; 

% Lateral force
Fy = Gyk .* Fy0 + SVyk;
end
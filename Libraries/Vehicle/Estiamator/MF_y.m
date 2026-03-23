function Fy = MF_y(Fz, alpha, kappa, lat)
%#codegen
coder.inline('always')
Amu = 1;
LMUY_prime = Amu * lat.LMUY / (1 + (Amu - 1) * lat.LMUY); 

% 1. Pure lateral
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
By = Ky / (Cy * Dy + 1e-6); 

% Pure lateral slip with slip angle shift
alphay = alpha + SHy; 
Fy0 = Dy * sin(Cy * atan(By * alphay - Ey *(By * alphay - atan(By * alphay))))+ SVy; %caz pur lateral  

% 2. Weighting function for combined slip
% Shift term
SHyk = lat.RHY1 + lat.RHY2 * dfz; 

% Shape (Cyk), Curvature (Eyk), and Stiffness (Byk)
Cyk = lat.RCY1;
Eyk = lat.REY1 + lat.REY2 * dfz;
Byk = lat.RBY1 * cos(atan(lat.RBY2 * (alpha - lat.RBY3))) * lat.LYKA;

% Weighting function term with kappa shift
kappas = kappa + SHyk; 
            
Gyk0 = cos(Cyk * atan(Byk * SHyk - Eyk * (Byk * SHyk - atan(Byk * SHyk)))); 
Gyk = cos(Cyk * atan(Byk * kappas - Eyk *(Byk * kappas - atan(Byk * kappas)))) / Gyk0; 

% 3. Kappa induced peak force (DVyk) and kappa induced side force (SVyk)
DVyk = muy * Fz * (lat.RVY1 + lat.RVY2 * dfz) * cos(atan(lat.RVY4 * alpha));  
SVyk = DVyk * sin(lat.RVY5 * atan(lat.RVY6 * kappa)) * lat.LVYKA; 

% 4. Lateral force

Fy = Gyk.*Fy0 + SVyk;

end

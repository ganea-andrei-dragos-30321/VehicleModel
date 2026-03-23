close all
if exist('out.logsout_sm_car', 'var')
    error('logsout_sm_car data not available.')
end

tout = out.tout;
logsout_VehBus = out.logsout_sm_car.get('VehBus');
%% FR
Bush.SuspF.LinkR.UA.Fr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushUA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushUA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushUA.Front.Fz.Data];

Bush.SuspF.LinkR.UA.Rr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushUA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushUA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushUA.Rear.Fz.Data];

Bush.SuspF.LinkR.LA.Fr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushLA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushLA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushLA.Front.Fz.Data];

Bush.SuspF.LinkR.LA.Rr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushLA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushLA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageR.BushLA.Rear.Fz.Data];

%% FL
Bush.SuspF.LinkL.UA.Fr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushUA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushUA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushUA.Front.Fz.Data];

Bush.SuspF.LinkL.UA.Rr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushUA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushUA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushUA.Rear.Fz.Data];

Bush.SuspF.LinkL.LA.Fr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushLA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushLA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushLA.Front.Fz.Data];

Bush.SuspF.LinkL.LA.Rr = [logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushLA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushLA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA1.LinkageL.BushLA.Rear.Fz.Data];

%% RR
Bush.SuspR.LinkR.UA.Fr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushUA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushUA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushUA.Front.Fz.Data];

Bush.SuspR.LinkR.UA.Rr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushUA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushUA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushUA.Rear.Fz.Data];

Bush.SuspR.LinkR.LA.Fr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushLA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushLA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushLA.Front.Fz.Data];

Bush.SuspR.LinkR.LA.Rr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushLA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushLA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageR.BushLA.Rear.Fz.Data];

%% RL
Bush.SuspR.LinkL.UA.Fr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushUA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushUA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushUA.Front.Fz.Data];

Bush.SuspR.LinkL.UA.Rr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushUA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushUA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushUA.Rear.Fz.Data];

Bush.SuspR.LinkL.LA.Fr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushLA.Front.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushLA.Front.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushLA.Front.Fz.Data];

Bush.SuspR.LinkL.LA.Rr = [logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushLA.Rear.Fx.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushLA.Rear.Fy.Data ...
                          logsout_VehBus.Values.Chassis.SuspA2.LinkageL.BushLA.Rear.Fz.Data];

figure Name FR_UA 
subplot(3,2,1)
plot(tout, Bush.SuspF.LinkR.UA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspF.LinkR.UA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspF.LinkR.UA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspF.LinkR.UA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspF.LinkR.UA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspF.LinkR.UA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name FR_LA 
subplot(3,2,1)
plot(tout, Bush.SuspF.LinkR.LA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspF.LinkR.LA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspF.LinkR.LA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspF.LinkR.LA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspF.LinkR.LA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspF.LinkR.LA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name FL_UA 
subplot(3,2,1)
plot(tout, Bush.SuspF.LinkL.UA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspF.LinkL.UA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspF.LinkL.UA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspF.LinkL.UA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspF.LinkL.UA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspF.LinkL.UA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name FL_LA 
subplot(3,2,1)
plot(tout, Bush.SuspF.LinkL.LA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspF.LinkL.LA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspF.LinkL.LA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspF.LinkL.LA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspF.LinkL.LA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspF.LinkL.LA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name RR_UA 
subplot(3,2,1)
plot(tout, Bush.SuspR.LinkR.UA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspR.LinkR.UA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspR.LinkR.UA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspR.LinkR.UA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspR.LinkR.UA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspR.LinkR.UA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name RR_LA 
subplot(3,2,1)
plot(tout, Bush.SuspR.LinkR.LA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspR.LinkR.LA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspR.LinkR.LA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspR.LinkR.LA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspR.LinkR.LA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspR.LinkR.LA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name RL_UA 
subplot(3,2,1)
plot(tout, Bush.SuspR.LinkL.UA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspR.LinkL.UA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspR.LinkL.UA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspR.LinkL.UA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspR.LinkL.UA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspR.LinkL.UA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');

figure Name RL_LA 
subplot(3,2,1)
plot(tout, Bush.SuspR.LinkL.LA.Fr(:,1));
title('Front Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,2)
plot(tout, Bush.SuspR.LinkL.LA.Rr(:,1));
title('Rear Fx'); xlabel('Time[s]'); ylabel('Fx[N]');
subplot(3,2,3)
plot(tout, Bush.SuspR.LinkL.LA.Fr(:,2));
title('Front Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,4)
plot(tout, Bush.SuspR.LinkL.LA.Rr(:,2));
title('Rear Fy'); xlabel('Time[s]'); ylabel('Fy[N]');
subplot(3,2,5)
plot(tout, Bush.SuspR.LinkL.LA.Fr(:,3));
title('Front Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
subplot(3,2,6)
plot(tout, Bush.SuspR.LinkL.LA.Rr(:,3));
title('Rear Fz'); xlabel('Time[s]'); ylabel('Fz[N]');
% Build checks list (adjust names if needed)
checks = {
 'FR_UA_Front',  Bush.SuspF.LinkR.UA.Fr;
 'FR_UA_Rear',   Bush.SuspF.LinkR.UA.Rr;
 'FR_LA_Front',  Bush.SuspF.LinkR.LA.Fr;
 'FR_LA_Rear',   Bush.SuspF.LinkR.LA.Rr;
 'FL_UA_Front',  Bush.SuspF.LinkL.UA.Fr;
 'FL_UA_Rear',   Bush.SuspF.LinkL.UA.Rr;
 'FL_LA_Front',  Bush.SuspF.LinkL.LA.Fr;
 'FL_LA_Rear',   Bush.SuspF.LinkL.LA.Rr;
 'RR_UA_Front',  Bush.SuspR.LinkR.UA.Fr;
 'RR_UA_Rear',   Bush.SuspR.LinkR.UA.Rr;
 'RR_LA_Front',  Bush.SuspR.LinkR.LA.Fr;
 'RR_LA_Rear',   Bush.SuspR.LinkR.LA.Rr;
 'RL_UA_Front',  Bush.SuspR.LinkL.UA.Fr;
 'RL_UA_Rear',   Bush.SuspR.LinkL.UA.Rr;
 'RL_LA_Front',  Bush.SuspR.LinkL.LA.Fr;
 'RL_LA_Rear',   Bush.SuspR.LinkL.LA.Rr
};

% Preallocate
n = size(checks,1);


Values_AtMaxFz_FrontSeries = NaN(n,3); % values when that entry's Front series Fz reaches its abs max (first occurrence)
Values_AtMaxFz_RearSeries  = NaN(n,3); % values when that entry's Rear  series Fz reaches its abs max (last occurrence)

Label = checks(:,1);
isFront = contains(Label, {'FR_','FL_'});
isRear  = contains(Label, {'RR_','RL_'});

Front_Forces = checks(isFront,2);
Rear_Forces  = checks(isRear,2);
for k = 1:numel(Front_Forces)
    [maxFz_F(k), maxIdx_F(k)] = max(abs(Front_Forces{k}(:,3)));
end
[elemMaxFz_F, elemId_F] = max(maxFz_F);
Idx_F = maxIdx_F(elemId_F);

% Rear check
for k = 1:numel(Rear_Forces)
    [maxFz_R(k), maxIdx_R(k)] = max(abs(Rear_Forces{k}(:,3)));
end
[elemMaxFz_R, elemId_R] = max(maxFz_R);
Idx_R = maxIdx_R(elemId_R);
for i = 1:n
    values = checks{i,2};
    Values_AtMaxFz_RearSeries(i, :) = values(Idx_R,:);
    Values_AtMaxFz_FrontSeries(i, :) = values(Idx_F,:);

end
Front_Table = array2table(Values_AtMaxFz_FrontSeries, ...
    'VariableNames', {'Fx','Fy','Fz'}, ...
    'RowNames', Label);
Front_Table.Properties.Description = 'Values [Fx Fy Fz] when each Front Pickup Points reach the absolute max Fz (first occurrence)';

Rear_Table = array2table(Values_AtMaxFz_RearSeries, ...
    'VariableNames', {'Fx','Fy','Fz'}, ...
    'RowNames', Label);
Rear_Table.Properties.Description = 'Values [Fx Fy Fz] when each Rear Pickup Points reach the absolute max Fz (first occurrence)';

% Export front and rear tables to Excel
outFilename = 'Suspension_Forces_AtMaxFz.xlsx';
% Combine into one file with two sheets
writetable(Front_Table, outFilename, 'Sheet', 'Front', 'WriteRowNames', true);
writetable(Rear_Table,  outFilename, 'Sheet', 'Rear',  'WriteRowNames', true);

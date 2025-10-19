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

figure Name RR_LA 
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
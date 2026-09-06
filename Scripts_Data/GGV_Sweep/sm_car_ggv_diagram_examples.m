%% GGV Diagram Generation from Virtual Tests
% 
% The commands below run a series of simulations on a full vehicle model to
% generate a GGV diagram.  For each test, 
% 
% * The vehicle is resting on a flat surface with the brakes applied
% * The vehicle is constrained so that it cannot yaw
% * A downforce and drag force are applied consistent with a given vehicle
% speed
% * The x- and y- components of the gravity vector are gradually increased
% until the vehicle starts to slide across the ground
% 
% Sets of points are collected around the friction circle in the xy-plane
% and at different vehicle speeds.  Plotting these points on a surface
% creates the GGV diagram.  This diagram is normally produced for
% quasi-steady state behavior.  These tests can be run sequentially or in
% parallel.
%
% Copyright 2018-2026 The MathWorks, Inc.

%% Open model

%% Generate GGV Diagram for Formula Student Vehicle
Vehicle.Chassis.Tire.class.Value = 'MFMbody';
[simOut1, simInput1, filename_ggv1] = sm_car_sweep_ggv_pts( ...
    'sm_car',Vehicle,16,linspace(2,20,8),false,false,false);
Vehicle.Chassis.Aero.CD.Value = 0.8;
Vehicle.Chassis.Aero.CL.Value = -0.9;
Vehicle.Chassis.Aero.sPressureCentre.Value = [-0.8 0 0.26];
Vehicle.Chassis.Aero.ARef.Value = 1;
[simOut2, simInput2, filename_ggv2] = sm_car_sweep_ggv_pts( ...
    'sm_car',Vehicle,16,linspace(2,20,8),false,false,false);

%% Compare GGV Diagrams on the same plot
load("GGV_2025.mat");
GGV_data1 = GGV_data;
load("GGV_2026.mat");
GGV_data2 = GGV_data;

clr_order = colororder('default');
fig_h = sm_car_plot_ggv_surf(GGV_data1,false,clr_order(1,:));
fig_h = sm_car_plot_ggv_surf(GGV_data2,true,clr_order(2,:));
legend({'2025','2026'},'Location','Best')
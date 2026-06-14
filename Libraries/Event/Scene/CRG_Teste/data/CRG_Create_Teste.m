function traj_coeff = CRG_Create_Teste
% CRG_Create_Custom    Create CRG file from centerline data
%
% If no outputs are requested, creates CRG and geometry files
%   Creates CRG file for track with and without elevation.
%   Creates STL files based on data in CRG file.
%
% If output is requested, provides default trajectory coefficients
%
% Copyright 2020-2024 The MathWorks, Inc.
file_data = readtable("CRG_Teste_centerline.xlsx");
if width(file_data)<5
    file_data(:,2) = file_data(:,2) - 1.8;
    dist_m(1,1) = 0;
    for i=2:height(file_data)
        dist_m(i,1) = dist_m(i-1,1) + norm([file_data{i,1},file_data{i,2},0] - [file_data{i-1,1},file_data{i-1,2},0]);
    end
   % file_data{:,1} = -file_data{:,1};
    dist=table(dist_m,dist_m/1000,'VariableNames',{'Distance_m','Distance_km'});
    writetable([file_data,dist],'CRG_Teste_centerline.xlsx','WriteMode','overwrite','WriteVariableNames',true);
    clear dist dist_m
end
clear file_data;
if(nargout == 0)
    road_opts.create_stl_files = true;
    road_opts.create_no_elevation = true;
    road_opts.create_stl_files_f = true;
    road_opts.decim_data = 1;  % Was 2
    road_opts.decim_alti = 32;
    road_opts.road_width = 1.7;      % Half width of the road
    road_opts.blending_distance = 10;
    road_opts.xa = 0;
    road_opts.xb = 0;
    road_opts.ya = 0.0;
    road_opts.yb = 0;
    road_opts.za = 0.0;
    road_opts.zb = 0;
    road_opts.reverse = 0;
    road_opts.datasrc = 'xyz';  % xyz or gps
    sm_car_centerline_to_crg('CRG_Teste',road_opts)
end

%% Create driver trajectory
traj_coeff.blend_distance = 10;     % m
traj_coeff.diff_exp       = 0.7;   % was 1.4, lower = more slowing in medium/high curvature
traj_coeff.diff_smooth    = 8;     % Diff smoothing number of points
traj_coeff.curv_smooth    = 10;    % Curvature smoothing number of points
traj_coeff.lim_smooth     = 50;    % was 100, lower = releases speed sooner after corners
traj_coeff.target_shape_smooth = 4; % was 8, lower = less exit-speed delay
traj_coeff.vmax           = 21;   % Max speed, m/s
traj_coeff.vmin           = 3;    % Min speed, m/s
traj_coeff.decimation     = 1;      % Decimation for interpolation

if(nargout == 0)
    % Create driver trajectory for road with elevation
    sm_car_trajectory_calc('CRG_Teste',traj_coeff)
    
    % Create driver trajectory for road with elevation
    sm_car_trajectory_calc('CRG_Teste_f',traj_coeff)
end
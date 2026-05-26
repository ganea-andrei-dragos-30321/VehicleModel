function traj_coeff = CRG_Create_Germania
% CRG_Create_Custom    Create CRG file from centerline data
%
% If no outputs are requested, creates CRG and geometry files
%   Creates CRG file for track with and without elevation.
%   Creates STL files based on data in CRG file.
%
% If output is requested, provides default trajectory coefficients
%
% Copyright 2020-2024 The MathWorks, Inc.
file_data = readtable("CRG_Germania_centerline.xlsx");
if width(file_data)<5
    dist_m(1,1) = 0;
    for i=2:height(file_data)
        dist_m(i,1) = dist_m(i-1,1) + norm([file_data{i,1},file_data{i,2},0] - [file_data{i-1,1},file_data{i-1,2},0]);
    end
    %file_data{:,1} = -file_data{:,1};
    dist=table(dist_m,dist_m/1000,'VariableNames',{'Distance_m','Distance_km'});
    writetable([file_data,dist],'CRG_Germania_centerline.xlsx','WriteMode','overwrite','WriteVariableNames',true);
    clear dist dist_m
end
clear file_data;
if(nargout == 0)
    road_opts.create_stl_files = true;
    road_opts.create_no_elevation = true;
    road_opts.create_stl_files_f = true;
    road_opts.decim_data = 1;  % Was 2
    road_opts.decim_alti = 32;
    road_opts.road_width = 1.77;      % Half width of the road
    road_opts.blending_distance = 10;
    road_opts.xa = 0;
    road_opts.xb = 0;
    road_opts.ya = 0.0;
    road_opts.yb = 0;
    road_opts.za = 0.0;
    road_opts.zb = 0;
    road_opts.reverse = 0;
    road_opts.datasrc = 'xyz';  % xyz or gps
    sm_car_centerline_to_crg('CRG_Germania',road_opts)
end

%% Create driver trajectory
traj_coeff.blend_distance = 10;     % m
traj_coeff.diff_exp       = 1.2;    % Curvature exponent
traj_coeff.diff_smooth    = 12;     % Diff smoothing number of points
traj_coeff.curv_smooth    = 20;    % Curvature smoothing number of points
traj_coeff.lim_smooth     = 100;    % Limit smoothing number of points
traj_coeff.target_shape_smooth = 8;  % Number of points for smoothing
traj_coeff.vmax           = 20;   % Max speed, m/s
traj_coeff.vmin           = 3;    % Min speed, m/s
traj_coeff.decimation     = 1;      % Decimation for interpolation

if(nargout == 0)
    % Create driver trajectory for road with elevation
    sm_car_trajectory_calc('CRG_Germania',traj_coeff)
    
    % Create driver trajectory for road with elevation
    sm_car_trajectory_calc('CRG_Germania_f',traj_coeff)
end
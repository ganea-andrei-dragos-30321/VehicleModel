function scene_data = sm_car_scenedata_crg_teste_f
%% Scene parameters
% Copyright 2018-2024 The MathWorks, Inc.

curr_dir = pwd;
cd(fileparts(which(mfilename)));

scene_data.Name               = 'CRG_Teste_F';
scene_data.CRGfile            = 'CRG_Teste_f.crg';
scene_data.Geometry.filename  = 'CRG_Dej_Wide.stl';
scene_data.Geometry.fileunits = 'm';
road_visual_y_offset          = 2;          % m, shifts DEJ Wide road visual right
scene_data.Geometry.clr   = [1 1 1]*0.8; % [R G B]
scene_data.Geometry.opc   = 1;           % (0-1)
scene_data.Geometry.x     = 0;           % m
scene_data.Geometry.y     = road_visual_y_offset; % m
scene_data.Geometry.z     = 0;           % m
scene_data.Geometry.yaw   = 0;           % rad
scene_data.Geometry.pitch = 0;           % rad
scene_data.Geometry.roll  = 0;           % rad
scene_data.Geometry.w     = 3;          % m

scene_data.Geometry.centerline.filename  = 'CRG_Teste_f_centerline.stl';
scene_data.Geometry.centerline.fileunits = 'm';
scene_data.Geometry.centerline.clr   = [1 1 1]*1; % [R G B]
scene_data.Geometry.centerline.opc   = 1;           % (0-1)
scene_data.Geometry.centerline.x     = 0;           % m
scene_data.Geometry.centerline.y     = 0;           % m
scene_data.Geometry.centerline.z     = 0.01;           % m
scene_data.Geometry.centerline.yaw   = 0;           % rad
scene_data.Geometry.centerline.pitch = 0;           % rad
scene_data.Geometry.centerline.roll  = 0;           % rad
teste_data = load('CRG_Teste_f_dat', 'dat');
teste_dat = teste_data.dat;
scene_data.Geometry.centerline.xyz   = [teste_dat.rx' teste_dat.ry' 0*teste_dat.rx']; % m
% If STL files do not exist, they will be created when scene is selected.

cone_data = sm_car_scene_crg_teste_cones_create(false);
scene_data.Cones = cone_data;
scene_data.Geometry.cones.fileunits = 'm';
scene_data.Geometry.cones.x     = 0;           % m
scene_data.Geometry.cones.y     = 0;           % m
scene_data.Geometry.cones.z     = 0;           % m
scene_data.Geometry.cones.yaw   = 0;           % rad
scene_data.Geometry.cones.pitch = 0;           % rad
scene_data.Geometry.cones.roll  = 0;           % rad

scene_data.Geometry.cones.body.filename  = cone_data.files.body;
scene_data.Geometry.cones.body.clr       = [248 78 25]/255;
scene_data.Geometry.cones.body.opc       = 1;

scene_data.Geometry.cones.strip.filename = cone_data.files.strip;
scene_data.Geometry.cones.strip.clr      = [0.75 0.75 0.75];
scene_data.Geometry.cones.strip.opc      = 1;

scene_data.Geometry.cones.base.filename  = cone_data.files.base;
scene_data.Geometry.cones.base.clr       = [248 78 25]/255;
scene_data.Geometry.cones.base.opc       = 1;

scene_data.Geometry.finish_line.post.height  = 6;             % m
scene_data.Geometry.finish_line.post.radius  = 0.5;           % m
scene_data.Geometry.finish_line.post.separation = 12;         % m
scene_data.Geometry.finish_line.post.clr     = [0.8 0.0 0.2]; % [R G B]
scene_data.Geometry.finish_line.post.opc     = 1;             % (0-1)
scene_data.Geometry.finish_line.offset.xyz   = scene_data.Geometry.centerline.xyz(1,:)+[0 2 0]; % m
scene_data.Geometry.finish_line.offset.yaw   = double(teste_dat.p(1));      % rad
scene_data.Geometry.finish_line.offset.pitch = 0;      % rad
scene_data.Geometry.finish_line.offset.roll  = 0;      % rad

cd(curr_dir);

function cone_data = sm_car_scene_crg_teste_cones_create(forceCreate)
%sm_car_scene_crg_teste_cones_create Create cone STL overlays for CRG Teste.
%   The cones are sampled from the flat CRG Teste centerline and offset to
%   both course boundaries using the road half-width stored in the CRG data.

if nargin < 1
    forceCreate = false;
end

curr_dir = pwd;
cleanupObj = onCleanup(@() cd(curr_dir));
cd(fileparts(which(mfilename)));

cone_data.files.body  = 'CRG_Teste_f_cones_body.stl';
cone_data.files.strip = 'CRG_Teste_f_cones_strips.stl';
cone_data.files.base  = 'CRG_Teste_f_cones_bases.stl';

if ~forceCreate ...
        && exist(cone_data.files.body, 'file') ...
        && exist(cone_data.files.strip, 'file') ...
        && exist(cone_data.files.base, 'file')
    load('CRG_Teste_f_cone_data.mat', 'cone_data');
    return
end

load('CRG_Teste_f_dat', 'dat');

track_width = 2 * double(dat.v(1));
half_width = track_width / 2;

x = double(dat.rx(:));
y = double(dat.ry(:));
if hypot(x(end) - x(1), y(end) - y(1)) < 1
    x(end) = [];
    y(end) = [];
end

[sample_idx, sample_s] = selectConeSamples(x, y);
[nx, ny] = centerlineNormals(x, y);

cone_ctr = [x(sample_idx), y(sample_idx), zeros(numel(sample_idx), 1)];
left_ctr = cone_ctr + half_width * [nx(sample_idx), ny(sample_idx), zeros(numel(sample_idx), 1)];
right_ctr = cone_ctr - half_width * [nx(sample_idx), ny(sample_idx), zeros(numel(sample_idx), 1)];
cone_xyz = [left_ctr; right_ctr];

cone_data.track_width = track_width;
cone_data.half_width = half_width;
cone_data.spacing_target = 5;
cone_data.spacing_corner = 3.5;
cone_data.sample_s = sample_s;
cone_data.centerline_xyz = cone_ctr;
cone_data.left_xyz = left_ctr;
cone_data.right_xyz = right_ctr;
cone_data.count_per_side = size(left_ctr, 1);
cone_data.count_total = size(cone_xyz, 1);

dims.height = 0.6;
dims.base_thickness = 0.04;
dims.base_width = 0.35;
dims.bottom_diameter = 0.24;
dims.top_diameter = 0.06;
dims.strip_height = 0.3;
dims.facets = 14;

[body_v, body_f, strip_v, strip_f, base_v, base_f] = buildConeMeshes(cone_xyz, dims);
writeAsciiStl(cone_data.files.body, body_v, body_f, 'crg_teste_cone_body');
writeAsciiStl(cone_data.files.strip, strip_v, strip_f, 'crg_teste_cone_strips');
writeAsciiStl(cone_data.files.base, base_v, base_f, 'crg_teste_cone_bases');

save('CRG_Teste_f_cone_data.mat', 'cone_data');

end

function [sample_idx, sample_s] = selectConeSamples(x, y)
target_spacing = 5;
corner_spacing = 3.5;
max_heading_change = deg2rad(8);
min_spacing = 3;

xy = [x(:), y(:)];
n = size(xy, 1);
next_xy = xy([2:n 1], :);
prev_xy = xy([n 1:n-1], :);

seg_len = hypot(next_xy(:, 1) - xy(:, 1), next_xy(:, 2) - xy(:, 2));
heading_prev = atan2(xy(:, 2) - prev_xy(:, 2), xy(:, 1) - prev_xy(:, 1));
heading_next = atan2(next_xy(:, 2) - xy(:, 2), next_xy(:, 1) - xy(:, 1));
heading_delta = abs(wrapToPiLocal(heading_next - heading_prev));

sample_idx = 1;
sample_s = 0;
distance_since = 0;
turn_since = 0;
cum_s = 0;

for i = 2:n
    distance_since = distance_since + seg_len(i - 1);
    turn_since = turn_since + heading_delta(i);
    cum_s = cum_s + seg_len(i - 1);

    local_spacing = target_spacing;
    if heading_delta(i) > deg2rad(3)
        local_spacing = corner_spacing;
    end

    if distance_since >= local_spacing || (distance_since >= min_spacing && turn_since >= max_heading_change)
        sample_idx(end + 1, 1) = i; %#ok<AGROW>
        sample_s(end + 1, 1) = cum_s; %#ok<AGROW>
        distance_since = 0;
        turn_since = 0;
    end
end
end

function [nx, ny] = centerlineNormals(x, y)
xy = [x(:), y(:)];
n = size(xy, 1);
next_xy = xy([2:n 1], :);
prev_xy = xy([n 1:n-1], :);
tangent = next_xy - prev_xy;
tangent_len = hypot(tangent(:, 1), tangent(:, 2));
tangent_len(tangent_len == 0) = 1;
tx = tangent(:, 1) ./ tangent_len;
ty = tangent(:, 2) ./ tangent_len;
nx = -ty;
ny = tx;
end

function angle = wrapToPiLocal(angle)
angle = mod(angle + pi, 2*pi) - pi;
end

function [body_v, body_f, strip_v, strip_f, base_v, base_f] = buildConeMeshes(centers, dims)
body_v = zeros(0, 3);
body_f = zeros(0, 3);
strip_v = zeros(0, 3);
strip_f = zeros(0, 3);
base_v = zeros(0, 3);
base_f = zeros(0, 3);

cone_height = dims.height - dims.base_thickness;
body_section_h = 0.5 * (dims.height - dims.base_thickness - dims.strip_height);
z0 = dims.base_thickness;
z1 = z0 + body_section_h;
z2 = z1 + dims.strip_height;
z3 = dims.height;

r0 = 0.5 * dims.bottom_diameter;
r3 = 0.5 * dims.top_diameter;
r1 = radiusAtZ(z1 - z0, cone_height, r0, r3);
r2 = radiusAtZ(z2 - z0, cone_height, r0, r3);

for i = 1:size(centers, 1)
    c = centers(i, :);
    [v, f] = frustumMesh(c, z0, z1, r0, r1, dims.facets);
    [body_v, body_f] = appendMesh(body_v, body_f, v, f);
    [v, f] = frustumMesh(c, z2, z3, r2, r3, dims.facets);
    [body_v, body_f] = appendMesh(body_v, body_f, v, f);

    [v, f] = frustumMesh(c, z1, z2, r1, r2, dims.facets);
    [strip_v, strip_f] = appendMesh(strip_v, strip_f, v, f);

    [v, f] = baseMesh(c, dims.base_width, dims.base_thickness);
    [base_v, base_f] = appendMesh(base_v, base_f, v, f);
end
end

function radius = radiusAtZ(z, height, r_bottom, r_top)
radius = r_bottom - z * (r_bottom - r_top) / height;
end

function [v, f] = frustumMesh(center, z_low, z_high, r_low, r_high, facets)
theta = linspace(0, 2*pi, facets + 1)';
theta(end) = [];

low = [center(1) + r_low * cos(theta), center(2) + r_low * sin(theta), center(3) + z_low + zeros(facets, 1)];
high = [center(1) + r_high * cos(theta), center(2) + r_high * sin(theta), center(3) + z_high + zeros(facets, 1)];
v = [low; high; center + [0 0 z_low]; center + [0 0 z_high]];

low_center = 2 * facets + 1;
high_center = 2 * facets + 2;
f = zeros(4 * facets, 3);
for k = 1:facets
    k2 = mod(k, facets) + 1;
    f(2*k - 1, :) = [k, k2, facets + k2];
    f(2*k, :) = [k, facets + k2, facets + k];
    f(2*facets + k, :) = [low_center, k2, k];
    f(3*facets + k, :) = [high_center, facets + k, facets + k2];
end
end

function [v, f] = baseMesh(center, width, height)
h = width / 2;
z0 = center(3);
z1 = center(3) + height;
x = center(1);
y = center(2);
v = [x-h y-h z0; x+h y-h z0; x+h y+h z0; x-h y+h z0; ...
     x-h y-h z1; x+h y-h z1; x+h y+h z1; x-h y+h z1];
f = [1 2 3; 1 3 4; 5 7 6; 5 8 7; ...
     1 5 6; 1 6 2; 2 6 7; 2 7 3; ...
     3 7 8; 3 8 4; 4 8 5; 4 5 1];
end

function [vertices, faces] = appendMesh(vertices, faces, new_vertices, new_faces)
faces = [faces; new_faces + size(vertices, 1)];
vertices = [vertices; new_vertices];
end

function writeAsciiStl(filename, vertices, faces, solidName)
fid = fopen(filename, 'w');
if fid == -1
    error('Unable to open %s for writing.', filename);
end
cleanupObj = onCleanup(@() fclose(fid));

fprintf(fid, 'solid %s\n', solidName);
for i = 1:size(faces, 1)
    tri = vertices(faces(i, :), :);
    normal = cross(tri(2, :) - tri(1, :), tri(3, :) - tri(1, :));
    normal_len = norm(normal);
    if normal_len > 0
        normal = normal / normal_len;
    end
    fprintf(fid, '  facet normal %.9g %.9g %.9g\n', normal);
    fprintf(fid, '    outer loop\n');
    fprintf(fid, '      vertex %.9g %.9g %.9g\n', tri(1, :));
    fprintf(fid, '      vertex %.9g %.9g %.9g\n', tri(2, :));
    fprintf(fid, '      vertex %.9g %.9g %.9g\n', tri(3, :));
    fprintf(fid, '    endloop\n');
    fprintf(fid, '  endfacet\n');
end
fprintf(fid, 'endsolid %s\n', solidName);
end

function [r1, r2] = testX

is_octave = (exist('octave_config_info') == 5);

if (~is_octave)
    ax_view = get(gca, 'x_ViewTransform');
    ax_proj = get(gca, 'x_ProjectionTransform');
    ax_viewport = get(gca, 'x_ViewPortTransform');
    ax_render = get(gca, 'x_RenderTransform');
    ax_normrender = get(gca, 'x_NormRenderTransform');
    do_warp = strcmp(get(gca, 'WarpToFill'), 'on');
else
    % this should somehow depend on plotboxaspectratiomode/dataaspectratiomode
    do_warp = 1;
end
ax_xlim = get(gca, 'XLim');
ax_ylim = get(gca, 'YLim');
ax_zlim = get(gca, 'ZLim');
pb = get(gca, 'PlotBoxAspectRatio');
set(gca, 'Units', 'pixels');
if (~is_octave)
    set(gcf, 'Units', 'pixels');
    fig_pos = floor(get(gcf, 'Position'));
else
    %canvas = __get_object__(gca).getCanvas();
    %fig_pos = [0 0 canvas.getWidth() canvas.getHeight()];
end
ax_pos = floor(get(gca, 'Position'));

xd = strcmp(get(gca, 'XDir'), 'reverse');
yd = strcmp(get(gca, 'YDir'), 'reverse');
zd = strcmp(get(gca, 'ZDir'), 'reverse');

axv = get(gca, 'View');
az = axv(1)*pi/180;
el = axv(2)*pi/180;

c_eye = get(gca, 'CameraPosition');
c_center = get(gca, 'CameraTarget');
c_upv = get(gca, 'CameraUpVector');
c_angle = get(gca, 'CameraViewAngle');
auto_cam = strcmp(get(gca, 'CameraPositionMode'), 'auto') && ...
           strcmp(get(gca, 'CameraTargetMode'), 'auto') && ...
           strcmp(get(gca, 'CameraUpVectorMode'), 'auto') && ...
           strcmp(get(gca, 'CameraViewAngleMode'), 'auto');

c_center_auto = [sum(ax_xlim)/2 sum(ax_ylim)/2 sum(ax_zlim)/2];
c_eye_auto = 5*norm(pb) * [cos(el)*sin(az) -cos(el)*cos(az) sin(el)] .* ...
    [diff(ax_xlim)/(1-2*xd) diff(ax_ylim)/(1-2*yd) diff(ax_zlim)/(1-2*zd)] ./ pb;
c_eye_auto = c_eye_auto + c_center_auto;
if (el == pi/2 || el == -pi/2)
    c_upv_auto = [-sin(az) cos(az) 0] .* ...
        [diff(ax_xlim)/(1-2*xd) diff(ax_ylim)/(1-2*yd) diff(ax_zlim)/(1-2*zd)] ./ pb;
else
    c_upv_auto = [0 0 1];
end

diffM = {};

% Pre-Transform

m_pre = scale(-(2*xd-1), -(2*yd-1), -(2*zd-1)) * scale(1/diff(ax_xlim), 1/diff(ax_ylim), 1/diff(ax_zlim));
m_pre2 = m_pre * translate(-ax_xlim(xd+1), -ax_ylim(yd+1), -ax_zlim(zd+1));
m_pre3 = scale(pb(1), pb(2), pb(3)) * translate(-0.5, -0.5, -0.5);

% View Transform

c_eye = m_pre3*m_pre2*[c_eye 1]';
c_center = m_pre3*m_pre2*[c_center 1]';
c_center2 = m_pre3*m_pre2*[mean(ax_xlim) mean(ax_ylim) mean(ax_zlim) 1]';
c_upv = scale(pb(1), pb(2), pb(3))*m_pre*[c_upv 1]';

F = (c_center(1:3)-c_eye(1:3));
F2 = c_center2(1:3)-c_eye(1:3);
f = F/norm(F);
UP = c_upv(1:3)/norm(c_upv(1:3));
if (abs(dot(f, UP)) > eps)
    UP = UP/sqrt(1-f(3)^2);
end
s = cross(f,UP);
u = cross(s,f);
%M = scale(1, 1, -1) * [s(:)'*2/sqrt(3) 0; u(:)'*2/sqrt(3) 0; -f(:)' 0; 0 0 0 1] * translate(-c_eye(1), -c_eye(2), -c_eye(3)) * m_pre3
M = scale(1, 1, -1) * [s(:)' 0; u(:)' 0; -f(:)' 0; 0 0 0 1] * translate(-c_eye(1), -c_eye(2), -c_eye(3)) * m_pre3;

%d = norm(pb)*5;
%m_view = translate(0, 0, d) * scale(1, 1, -1) * ...
%    rotate(el-pi/2, 1) * rotate(-az, 3) * scale(pb(1), pb(2), pb(3)) * ...
%    translate(-0.5, -0.5, -0.5);
m_view = M;
if (~is_octave)
    if (any(any(abs(ax_view-m_view)>1e-10)))
        diffM{end+1} = ax_view;
        diffM{end+1} = m_view;
        disp('View XForm does not match');
    else
        disp('View XForm match');
    end
else
    m_view
end

% Projection Transform

u = 1; v = 1; w = 1;
x = m_view*[0 u 0 0 u u 0 u;...
            0 0 v 0 v 0 v v;...
            0 0 0 w 0 w w w;...
            1 1 1 1 1 1 1 1];
dx = (max(x(1:3,:),[],2)-min(x(1:3,:),[],2));
% if (do_warp)
%     if (dx(1) <= dx(2))
%         f = 1/dx(2);
%     else
%         f = 1/dx(1);
%     end
% else
%     if (ax_pos(3)/ax_pos(4) > dx(1)/dx(2))
%         f = 1/dx(2);
%     else
%         f = 1/dx(1);
%     end
% end
f = 1/(2*tan((c_angle/2)*pi/180)*norm(F));
m_proj = scale(f, f, 1);
if (~is_octave)
    if (any(any(abs(ax_proj-m_proj)>1e-10)))
        diffM{end+1} = ax_proj;
        diffM{end+1} = m_proj;
        disp('Projection XForm does not match');
    else
        disp('Projection XForm match');
    end
else
    m_proj
end

if (do_warp)
    c_angle_auto = 1/max(dx(1), dx(2));
else
    if (ax_pos(3)/ax_pos(4) > dx(1)/dx(2))
        c_angle_auto = 1/dx(2);
    else
        c_angle_auto = 1/dx(1);
    end
end
c_angle_auto = 2*(180/pi)*atan(1/(2*c_angle_auto*norm(F)));

% Viewport Transform

if (do_warp)
    dx = dx*f;
    m_viewport = translate(ax_pos(1)+ax_pos(3)/2, fig_pos(4)-(ax_pos(2)+ax_pos(4)/2)+1, 0) * ...
        scale(ax_pos(3)/dx(1), -ax_pos(4)/dx(2), 1);
else
    if (auto_cam)
        if (ax_pos(3)/ax_pos(4) > dx(1)/dx(2))
            pix = min(ax_pos(3), ax_pos(4));
        else
            pix = max(ax_pos(3), ax_pos(4));
        end
    else
        pix = min(ax_pos(3), ax_pos(4));
    end
    m_viewport = translate(ax_pos(1)+ax_pos(3)/2, fig_pos(4)-(ax_pos(2)+ax_pos(4)/2)+1, 0) * ...
        scale(pix, -pix, 1);
end
if (~is_octave)
    if (any(any(abs(ax_viewport([1,2,4],:)-m_viewport([1,2,4],:))>1e-10)))
        diffM{end+1} = ax_viewport([1,2,4],:);
        diffM{end+1} = m_viewport([1,2,4],:);
        disp('Viewport XForm does not match');
    else
        disp('Viewport XForm match');
    end
else
    m_viewport([1,2,4],:)
end

% Normalized Render Transform

m_normrender = m_viewport*m_proj*m_view;
if (~is_octave)
    if (any(any(abs(ax_normrender([1,2,4],:)-m_normrender([1,2,4],:))>1e-10)))
        diffM{end+1} = ax_normrender([1,2,4],:);
        diffM{end+1} = m_normrender([1,2,4],:);
        disp('NormRender XForm does not match');
    else
        disp('NormRender XForm match');
    end
else
    m_normrender
end

% Render Transform

m_render = m_normrender*m_pre;
if (~is_octave)
    if (any(any(abs(ax_render([1,2,4],:)-m_render([1,2,4],:))>1e-10)))
        diffM{end+1} = ax_render([1,2,4],:);
        diffM{end+1} = m_render([1,2,4],:);
        disp('Render XForm does not match');
    else
        disp('Render XForm match');
    end
else
    m_render
end

r1 = m_render;
r2 = m_normrender;

if (strcmp(get(gca, 'CameraTargetMode'), 'auto'))
    if (any(abs(c_center_auto-get(gca, 'CameraTarget'))>1e-10))
        diffM{end+1} = get(gca, 'CameraTarget');
        diffM{end+1} = c_center_auto;
        disp('CameraTarget does not match');
    else
        disp('CameraTarget match');
    end
end

if (strcmp(get(gca, 'CameraPositionMode'), 'auto'))
    if (any(abs(c_eye_auto-get(gca, 'CameraPosition'))>1e-10))
        diffM{end+1} = get(gca, 'CameraPosition');
        diffM{end+1} = c_eye_auto;
        disp('CameraPosition does not match');
    else
        disp('CameraPosition match');
    end
end

if (strcmp(get(gca, 'CameraUpVectorMode'), 'auto'))
    if (any(abs(c_upv_auto-get(gca, 'CameraUpVector'))>1e-10))
        diffM{end+1} = get(gca, 'CameraUpVector');
        diffM{end+1} = c_upv_auto;
        disp('CameraUpVector does not match');
    else
        disp('CameraUpVector match');
    end
end

if (strcmp(get(gca, 'CameraViewAngleMode'), 'auto'))
    if (abs(c_angle_auto-get(gca, 'CameraViewAngle'))>1e-10)
        diffM{end+1} = get(gca, 'CameraViewAngle');
        diffM{end+1} = c_angle_auto;
        disp('CameraViewAngle does not match');
    else
        disp('CameraViewAngle match');
    end
end

% Report

if (~isempty(diffM))
    diffM{:}
end

function M = rotate(a, idx)

switch idx
    case 1
        M = [1 0 0 0; 0 cos(a) -sin(a) 0; 0 sin(a) cos(a) 0; 0 0 0 1];
    case 2
        M = [cos(a) 0 sin(a) 0; 0 1 0 0; -sin(a) 0 cos(a) 0; 0 0 0 1];
    case 3
        M = [cos(a) -sin(a) 0 0; sin(a) cos(a) 0 0; 0 0 1 0; 0 0 0 1];
end

function M = translate(x, y, z)

M = [eye(3) [x;y;z]; 0 0 0 1];

function M = scale(x, y, z)

M = [diag([x, y, z]) zeros(3,1); 0 0 0 1];

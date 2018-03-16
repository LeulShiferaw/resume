% Shows the screw-axis and the rotation and translation about it for the 
% space-ship motion in show_object_hierarchy.m

% This first section is the same as show_object_hierarchy.m
%%
clear all
clf
handle_axes= axes('XLim', [-4,4], 'YLim', [-4,4], 'ZLim', [-4,4]);
xlabel('e_1');
ylabel('e_2');
zlabel('e_3');

view(3);
grid on;
axis equal
camlight


trf_root= hgtransform('Parent', handle_axes);
h_original_ship= make_spaceship(trf_root, 0.2);

trf_ship2_root= hgtransform('Parent', trf_root);
h_ship2= make_spaceship(trf_ship2_root, 0.8);

roll= -pi/10;
pitch= pi/8;
yaw= pi;

trf_roll= makehgtform('xrotate', roll);
trf_pitch= makehgtform('yrotate', pitch);
trf_yaw= makehgtform('zrotate', yaw);
trf_rpy= trf_yaw*trf_pitch*trf_roll;

translation= [4,2,4]; % 4,2,2
trf_translate= makehgtform('translate', translation);
trf_final= trf_translate*trf_rpy;

set(trf_ship2_root, 'Matrix', trf_final);
drawnow;
%%  
% Create an intermediate ship which does the rotation about the screw-line for the transform
% between the original ship and ship2.
% Use equation (5.51) to find P*. C is coincident with O_E.

R_rpy = trf_rpy(1:3, 1:3)
[a, alpha] = DCM2AA(R_rpy);

% Position vector of P*
r_P= 0.5*cot(alpha/2)*cross(a, translation) - 0.5*cross(a, cross(a, translation));

% Draw the screw-axis line
mu= linspace(-4, 4, 2);
screw_line_x= r_P(1) + a(1)*mu;
screw_line_y= r_P(2) + a(2)*mu;
screw_line_z= r_P(3) + a(3)*mu;

hold on;
plot3(screw_line_x, screw_line_y, screw_line_z, 'r-', 'LineWidth', 2);

plot3([0 r_P(1)], [0 r_P(2)], [0 r_P(3)], 'b--', 'LineWidth', 2);

trf_1= makehgtform('translate', -r_P);
trf_2= makehgtform('axisrotate', a, alpha)
trf_3= makehgtform('translate',  r_P);

trf_rot_screw= trf_3 * trf_2 * trf_1; % Note the order

trf_ship_intermediate_root= hgtransform('Parent', trf_root);
h_ship_intermediate= make_spaceship(trf_ship_intermediate_root, 0.5);

set(trf_ship_intermediate_root, 'Matrix', trf_rot_screw);
drawnow;



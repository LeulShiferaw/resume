% Shows the initial and final pose of a space-ship which undergoes
% roll-pitch-yaw and translation.
% Look at slides 169-170.
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

% Change make_spaceship_ms to
% make_spaceship for the original version.
trf_root= hgtransform('Parent', handle_axes);
h_original_ship= make_spaceship_ms(trf_root, 0.2);

trf_ship2_root= hgtransform('Parent', trf_root);
h_ship2= make_spaceship_ms(trf_ship2_root, 0.8);

roll= -pi/10;
pitch= pi/8;
yaw= pi;

trf_roll= makehgtform('xrotate', roll);
trf_pitch= makehgtform('yrotate', pitch);
trf_yaw= makehgtform('zrotate', yaw);
trf_rpy= trf_yaw*trf_pitch*trf_roll;

translation= [4,2,4]; % 4,2,2
trf_translate= makehgtform('translate', translation);
%trf_final= trf_translate*trf_rpy;
trf_final= trf_rpy*trf_translate;

set(trf_ship2_root, 'Matrix', trf_final);
drawnow;


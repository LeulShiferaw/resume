%Submitted by :-
%Hisham Qanadilo(Matr No: 30000611)
%Leul Shiferaw(Matr No: 30000723)
%Aavash Shrestha(Matr No: 30000687

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

% Create ship-1
trf_ship1_root= hgtransform('Parent', handle_axes);
h_original_ship= make_spaceship(trf_ship1_root, 0.2);

% Create ship-2 translated and rotated w.r.t. ship-1
trf_ship2_ship1= hgtransform('Parent', trf_ship1_root);
h_ship2= make_spaceship(trf_ship2_ship1, 0.8);

roll= -pi/10;
pitch= pi/8;
yaw= pi;

trf_roll= makehgtform('xrotate', roll);
trf_pitch= makehgtform('yrotate', pitch);
trf_yaw= makehgtform('zrotate', yaw);
trf_rpy= trf_yaw*trf_pitch*trf_roll;

translation= [3,2,3]; % 4,2,2
trf_translate= makehgtform('translate', translation);
trf_final= trf_translate*trf_rpy;

set(trf_ship2_ship1, 'Matrix', trf_final);
drawnow;


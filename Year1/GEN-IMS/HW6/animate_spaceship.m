% Leul Shiferaw and Aavash Shrestha
% HW-6: This is the main script to call from the command-line
% to animate the space-ship.
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

% This is the marker ship for the initial (original) pose.
trf_root= hgtransform('Parent', handle_axes);
h_original_ship= make_spaceship(trf_root, 0.2);

% This is the ship-object which actually moves.
trf_ship2_root= hgtransform('Parent', trf_root);
h_ship2= make_spaceship(trf_ship2_root, 0.8);

% This is the marker ship for the final pose.
trf_ship2final_root= hgtransform('Parent', trf_root);
h_ship2final= make_spaceship(trf_ship2final_root, 0.2);

roll= -pi/10;
pitch= pi/8;
yaw= pi;
    
trf_roll= makehgtform('xrotate', roll);
trf_pitch= makehgtform('yrotate', pitch);
trf_yaw= makehgtform('zrotate', yaw);

trf_rpy= trf_yaw * trf_pitch * trf_roll; % Fill-in: Multiply the above three roll-pitch-yaw transforms in the right order

translation= [4,2,2];
trf_translate= makehgtform('translate', translation);

trf_final = trf_translate * trf_rpy; % Fill-in: Multiply trf_rpy and trf_translate in the right order

set(trf_ship2final_root, 'Matrix', trf_final);
drawnow;
pause(1);

rot_final= trf_final(1:3, 1:3);
q_final= DCM2Quat(rot_final);
trans_final= trf_final(1:3, 4);

q_initial= [1; 0; 0; 0];
trans_initial= zeros(3,1);

t_end= 1; % set t_end > 1 to extrapolate beyond final pose

for k=1:5  % Animate 5 times
    for t=0:0.01:t_end  
        
        % Interpolate quaternion
        q_t= SLERP(q_initial, q_final, t);
        trf_final(1:3, 1:3)= Quat2DCM(q_t);        
        
        % Interpolate translation
        trans_t= trans_initial + t*(trans_final - trans_initial);
        trf_final(1:3, 4)= trans_t;
        
        set(trf_ship2_root, 'Matrix', trf_final);
        drawnow;
        pause(0.01);
    end
end


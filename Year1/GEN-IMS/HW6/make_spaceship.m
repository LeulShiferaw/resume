function [ myhandles ] = make_spaceship(trf_root, transparency)
% Makes a space-ship with the root transform as the given transform.
% The surfaces are drawn with the given transparency in [0,1]
% A vector of handles to all the surfaces is returned.

ship_dish_profile= 2*sin(linspace(0, pi, 15));
[Xc, Yc, Zc]= cylinder(ship_dish_profile);

% Top dish
trf_top_root= hgtransform('Parent', trf_root);
set(trf_top_root, 'Matrix', makehgtform('translate', [0, 0, -0.2]));
color_top= [0, 1, 1];
myhandles(1)= surface(Xc, Yc, Zc, 'Parent', trf_top_root, 'FaceColor', color_top, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_top, 'EdgeAlpha', transparency);

% Bottom dish
trf_bottom_root= hgtransform('Parent', trf_root);
set(trf_bottom_root, 'Matrix', makehgtform('translate', [0, 0, 0.2]));
color_bottom= [0, 1, 1];
myhandles(2)= surface(Xc, Yc, Zc, 'Parent', trf_bottom_root, 'FaceColor', color_bottom, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_bottom, 'EdgeAlpha', transparency);

% Unit cylinder with a given profile (tapering at the ends).
% This is reused twice to create the two tails of the ship.
base_cylinder = [0.1, 0.2, 0.3, 0.3, 0.2, 0.1]
[Xt, Yt, Zt]= cylinder([base_cylinder 0.2]);  

% Left tail
trf_tailleft_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,3.5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-2.5, 0.75, 2]);
% Interpret the order as BFT (left to right)
set(trf_tailleft_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_tail_left= [0, 0, 1]; % reddish
myhandles(3)= surface(Xt, Yt, Zt, 'Parent', trf_tailleft_root, 'FaceColor', color_tail_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_tail_left, 'EdgeAlpha', transparency);

% Right tail
trf_tailright_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,3.5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-2.5, -0.75, 2]);
set(trf_tailright_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_tail_right= [0, 0, 1]; % drab olive
myhandles(4)= surface(Xt, Yt, Zt, 'Parent', trf_tailright_root, 'FaceColor', color_tail_right, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_tail_right, 'EdgeAlpha', transparency);

% Base tail 
[Xb, Yb, Zb]= cylinder([0.2, 0.175, 0.15, 0.15, 0.15, 0.15]);
trf_b_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,2.5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-1.5, 0, -0.5]);
set(trf_b_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color= [0, 0, 0];
myhandles(5)= surface(Xb, Yb, Zb, 'Parent', trf_b_root, 'FaceColor', color, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color, 'EdgeAlpha', transparency);

%sphere 
[Xs, Ys, Zs] = sphere;
trf_s_root= hgtransform('Parent', trf_root);
set(trf_s_root, 'Matrix', makehgtform('translate', [0, 0, 1]));
color = [0 , 1, 0];
myhandles(6) = surface(0.5*Xs, 0.5*Ys, 0.5*Zs,'Parent', trf_s_root,'Facecolor',color,'FaceAlpha',transparency,'EdgeAlpha',transparency);

%connector1 
[Xc1, Yc1, Zc1]= cylinder([0.1, 0.1, 0.1, 0.1, 0.1, 0.1]);
trf_c1_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,2.75]);
trf_Ry= makehgtform('yrotate', -pi/9);
trf_Rx = makehgtform('xrotate', -pi/10);
trf_T= makehgtform('translate', [-3, 0, -0.5]);
set(trf_c1_root, 'Matrix', trf_T*trf_Ry*trf_Rx*trf_scale);
color= [1, 1, 1 ];
myhandles(7)= surface(Xc1, Yc1, Zc1, 'Parent', trf_c1_root, 'FaceColor', color, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color, 'EdgeAlpha', transparency);

%connector2
[Xc2, Yc2, Zc2]= cylinder([0.1, 0.1, 0.1, 0.1, 0.1, 0.1]);
trf_c2_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,2.75]);
trf_Ry= makehgtform('yrotate', -pi/9);
trf_Rx = makehgtform('xrotate', pi/10);
trf_T= makehgtform('translate', [-3, 0, -0.5]);
set(trf_c2_root, 'Matrix', trf_T*trf_Ry*trf_Rx*trf_scale);
myhandles(8)= surface(Xc2, Yc2, Zc2, 'Parent', trf_c2_root, 'FaceColor', color, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color, 'EdgeAlpha', transparency);

%connector3
[Xc3, Yc3, Zc3]= cylinder([0.1, 0.1, 0.1, 0.1, 0.1, 0.1]);
trf_c3_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,1.5]);
trf_Ry= makehgtform('yrotate', pi/3);
trf_T= makehgtform('translate', [-2.5, 0, -0.5]);
set(trf_c3_root, 'Matrix', trf_T*trf_Ry*trf_scale);
myhandles(9)= surface(Xc3, Yc3, Zc3, 'Parent', trf_c3_root, 'FaceColor', color, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color, 'EdgeAlpha', transparency);

%fire1
[Xf, Yf, Zf]= cylinder([-0.2, 0.175, -0.15, 0.1, 0]);
trf_f_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,1.5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-6.25, 0.75, 2]);
% Interpret the order as BFT (left to right)
set(trf_f_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color= [1, 0, 0]; % reddish
myhandles(10)= surface(Xf, Yf, Zf, 'Parent', trf_f_root, 'FaceColor', color, 'FaceAlpha', .5, 'EdgeColor', 0.5*color, 'EdgeAlpha', .5);

%fire2
[Xf, Yf, Zf]= cylinder([-0.2, 0.175, -0.15, 0.1, 0]);
trf_f_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,1.5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-6.25, -0.75, 2]);
% Interpret the order as BFT (left to right)
set(trf_f_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color= [1, 0, 0]; % reddish
myhandles(11)= surface(Xf, Yf, Zf, 'Parent', trf_f_root, 'FaceColor', color, 'FaceAlpha', .5, 'EdgeColor', 0.5*color, 'EdgeAlpha', .5);


end


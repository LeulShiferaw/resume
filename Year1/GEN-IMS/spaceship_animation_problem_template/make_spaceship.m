function [ myhandles ] = make_spaceship(trf_root, transparency)
% Makes a space-ship with the root transform as the given transform trf_root.
% The surfaces are drawn with the given transparency in [0,1]
% A vector of handles to all the surfaces is returned.

ship_dish_profile= 2*sin(linspace(0, pi, 15));
[Xc, Yc, Zc]= cylinder(ship_dish_profile);

% Top dish
trf_top= hgtransform('Parent', trf_root);
set(trf_top, 'Matrix', makehgtform('translate', [0, 0, -0.2]));
color_top= [0.490196, 0.619608, 0.752941];
myhandles(1)= surface(Xc, Yc, Zc, 'Parent', trf_top, 'FaceColor', color_top, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_top, 'EdgeAlpha', transparency);

% Bottom dish
trf_bottom= hgtransform('Parent', trf_root);
set(trf_bottom, 'Matrix', makehgtform('translate', [0, 0, 0.2]));
color_bottom= [0.5, 0.5, 1];
myhandles(2)= surface(Xc, Yc, Zc, 'Parent', trf_bottom, 'FaceColor', color_bottom, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_bottom, 'EdgeAlpha', transparency);


[Xt, Yt, Zt]= cylinder([0, 0.3, 0.4, 0.4, 0.3, 0]); % unit cylinder 

% Left tail
trf_tail_left= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-0.2, 0.75, 0.5]);
set(trf_tail_left, 'Matrix', trf_T*trf_Ry*trf_scale);
color_tail_left= [1 0.388235 0.278431]; % reddish
myhandles(3)= surface(Xt, Yt, Zt, 'Parent', trf_tail_left, 'FaceColor', color_tail_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_tail_left, 'EdgeAlpha', transparency);

% Right tail
trf_tail_right= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,5]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-0.2, -0.75, 0.5]);
set(trf_tail_right, 'Matrix', trf_T*trf_Ry*trf_scale);
color_tail_right= [0.556863 0.556863 0.219608]; % drab olive
myhandles(4)= surface(Xt, Yt, Zt, 'Parent', trf_tail_right, 'FaceColor', color_tail_right, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_tail_right, 'EdgeAlpha', transparency);


end


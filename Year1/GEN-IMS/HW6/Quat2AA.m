function [axis, angle] = Quat2AA( q )
% q is a unit-quaternion ( a normalized 4 vector )
% returns axis (a unit vector) and angle in radians.

% Fill-in
angle = 2*acos(q(1, 1));
if angle/2 == 0
   a1 = 0;
   a2 = 0;
   a3 = 0;
else 
    a1 = q(2, 1)/sin(angle/2);
    a2 = q(3, 1)/sin(angle/2);
    a3 = q(4, 1)/sin(angle/2);
end

axis = [a1; a2; a3];

end
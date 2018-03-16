function [ axis, angle ] = DCM2AA( R )
% R should be a DCM. Returns the equivalent axis-angle representation.
% This is the inverse of the function Rodrigues

% Fill-in
angle = acos((trace(R)-1)/2);
    
A  = (1/(2*sin(angle)))*(R - R');
    
a1 = A(3,2);
a2 = A(1,3);
a3 = A(2,1);
axis = [a1;a2;a3];


end


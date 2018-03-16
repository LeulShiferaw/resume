function [ R ] = Quat2DCM( q )
% q is a unit-quaternion (a normalized 4 vector)
% returns R, the equivalent DCM.

q= q/norm(q); % Normalize it, do not assume that the user did
% Compute R using the method shown in the tutorial before MSE, or 
% directly use Eq. (1.31) on page 38 of the textbook.

% Fill-in

[axis, angle] = Quat2AA(q);

R = Rodrigues(axis, angle);
end


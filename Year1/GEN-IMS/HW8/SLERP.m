function qt = SLERP( q0, q1, t )
% q0 is the unit-quaternion of the start-rotation
% q1 is the unit-quaternion of the final-rotation
% t is an interpolation parameter between 0 and 1. 
% If t>1 is supplied then extrapolation occurs.
% returns qt the interpolated unit-quaternion.

% Fill-in

qt = QuatMult(q0,QuatPower(QuatMult(QuatConj(q0),q1), t));

end
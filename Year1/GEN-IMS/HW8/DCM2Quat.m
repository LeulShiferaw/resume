function q = DCM2Quat( R )
% q is a unit quaternion, R is a DCM 

[axis, angle] = DCM2AA(R);
p= angle/2;
q= [cos(p); sin(p)*axis];
end

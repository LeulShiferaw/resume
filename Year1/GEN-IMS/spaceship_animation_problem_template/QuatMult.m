function rQ = QuatMult( pQ, qQ )
% pQ, qQ are quaternions (4 vectors)
% returns rQ which the quaternion product of pQ and qQ.
% Refer to Eq. (4.102) on slide 122.

% Fill-in
p0 = pQ(1,1);
q0 = qQ(1,1); 
p = [pQ(2,1);pQ(3,1);pQ(4,1)];
q = [qQ(2,1);qQ(3,1);qQ(4,1)];
temp = p0*q + q0*p + cross(p, q);
rQ = [p0*q0 - dot(p,q); temp];
end
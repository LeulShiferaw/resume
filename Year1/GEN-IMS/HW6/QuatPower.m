function qp = QuatPower(q, t)
% q is a quaternion (a 4 vector)
% returns q to the power t.
% Refer to Eq. (4.117) on slide 128.
% Warning: In (4.117), theta is twice the rotation-angle: 
% Look at Theorem 13 on slide 125.

% Fill-in
[ax, an] = Quat2AA(q);
qp = [cos(t*an/2); sin(t*an/2)*ax];
end
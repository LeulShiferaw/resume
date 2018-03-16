function R_B_E= Rodrigues(a_E, alpha)
% Converts axis angle to DCM.
% a_E is the rotation-axis resolved in frame E (it will be normalized)
% alpha is the rotation-angle about a_E.
% Returns the equivalent DCM R_B_E.
% This is the inverse of the function DCM2AA
if norm(a_E) == 0
    a = a_E;
else
    a = a_E./norm(a_E);
end
A= crosspr(a);
R_B_E= eye(3) + sin(alpha)*A + (1-cos(alpha))*(A*A);
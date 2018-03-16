function [C,vn]= crosspr(v, normalize)
% This function returns the cross-product matrix 
% v is the input vector
% if normalize is true, v is normalized before
% computing the matrix
% C is the output matrix
% If vn is needed, it is set to the norm of v.
% This function illustrates the use of optional input and output arguments.

a= norm(v);
if (nargin == 2)
    if normalize
        v= v./a;
    end
end
        
C= [0, -v(3), v(2); ...
    v(3), 0, -v(1); ...
    -v(2), v(1), 0];

if nargout==2
    vn= a;
end
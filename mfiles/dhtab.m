function H=fkin(q,M)
%  fkin(M,q)
%  
%  Computes the robot foward kinamtic using the
%  the
%
%   q : Array of joints angles
%   q= [ q1,q2 ... ]
%
%   M : Matrix of constant denavit parameters
%   M= [ alpha  ,  d, a ]
%
%
%   Returns:
%
%   H=[ n s a p]
%     [ 0 0 0 1]
%
N=size(M)
N=n(1)


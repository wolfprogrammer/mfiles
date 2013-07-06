function [H]=fkin(q,M)
%  fkin(q,M)
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
%   [ H1,H2,H3...Hn]
%
%   Ht=[ n s a p]
%      [ 0 0 0 1]
%
%
N=size(M)  ; % Numbers of rows of matrix M 
N=N(1)     ;
HH=eye(4)  ; % Indentity matrix 4X4

for i=1:N          ;
 %   disp(i)        ;
    theta=q(i)     ;
    alpha=M(i,1)   ;
    d=M(i,2)       ;
    a=M(i,3)       ;
    Ht=DH(theta,alpha,d,a) ;      
    HH=HH*Ht      ;
endfor

H=HH;

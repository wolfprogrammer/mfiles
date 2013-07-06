function  H = DH(theta,alpha,d,a)
% DH(theta,alpha,d,a) 
% Computes the denavit hartenberg parameters
%
% theta: Angle from  Xi-1 to Xi
% alpha: Angle from  Zi-1  to Zi
% d    : Distance from Xi-1 to Xi
% a    : Distance from Zi-1 to Zi
%
%
%   Returns   the tranformation matrix from the frame i-1 to frame i
%
%    i-1
%       H
%        i
%
d2r=pi/180;
theta=theta*d2r;
alpha=alpha*d2r;

H=zeros(4,4);
H(1,1) = cos(theta);
H(1,2) = -cos(alpha)*sin(theta);
H(1,3) = sin(alpha)*sin(theta);
H(1,4) = a*cos(theta);
H(2,1) = sin(theta);
H(2,2) = cos(alpha)*cos(theta);
H(2,3) = -sin(alpha)*cos(theta);
H(2,4) = a*sin(theta);
H(3,1) = 0;
H(3,2) = sin(alpha);
H(3,3) = cos(alpha);
H(3,4) = d;
H(4,1) = 0;
H(4,2) = 0;
H(4,3) = 0;
H(4,4) = 1; 
     


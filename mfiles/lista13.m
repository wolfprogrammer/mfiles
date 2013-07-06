me=2*1e-3
M=30.0

wn=550 % cpm
wn=wn/60*(2*pi)  % rad/s

w=1200           % rpm
w=pi/30*w        % 

z=0.2

r=w/wn


hr=r^2/sqrt((1-r^2)^2+4*z^2*r^2)
X=me/M*hr

%------------------------------------------------------------------%
disp 'Balancemaneto do eixo'
X=200e-6
me=M*X/hr
% 	      servo.m
%
%  Considera-se
%
%  1ms -   0 graus
%  2ms - 180 graus

% Fatores multiplicadores de unidades
ms=1e-3;
us=1e-6;
MHZ=1e6;

% Input parameters
Fclk = 48*MHZ
Nint = 30     % Interrupt period in terms of ( instruction numbers)

%--------- Calculated parameters ---------- %
t000deg= 1*ms
t180deg= 2*ms 
t150deg=1.5*ms
Tpulse=20*ms

Tcy=4/Fclk
Tint= Nint*Tcy
fint=1/Tint
% Number of angles
N=(t180deg-t000deg)/Tint
N=round(N)
% Resolution degrees/count
resol=180/N

N1=t000deg/Tint
N2=t180deg/Tint
N3=t150deg/Tint
Ntot=Tpulse/Tint
%resl=0.1 % Resolução em graus









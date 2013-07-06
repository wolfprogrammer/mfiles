%			PWM.m
%  
%   Configure the PWM for the PIC18f4550 and PIC18F series
%


%-----------------------------------------------%
%    	         DATA ENTRY                     %
%-----------------------------------------------%
disp('---------- Input Values------------------')
% XTAL/HSTAL CPU frequency in MHZ
Fosc= 4
% PWM frequency in kHZ
fpwm = input("Entre com a frequencia em KHZ")
% PWM bits
Nbits=10
% PWM Voltage
V=5

%-----------------------------------------------%
%    	       CALCULATIONS                     %
%-----------------------------------------------%
disp('----------Calculations------------------')

Fosc= 1e6*Fosc; % To Hz
fpwm= 1e3*fpwm; % To KHz
Tosc=1/Fosc	% S
Tpwm=1/fpwm

% Max duty cycle in bits
dcmax=2^Nbits-1; 
% Duty Cycle in bits from 0 to dcmax
% it is the value of CCPRxL:CCPxCON register
dc=0:dcmax;	


% Maximum PWM resolution in bits 
PWMresolution= round(log10(Fosc/fpwm)/log10(2))

presc=[1 4 16]  % Timer 2 Prescaler

% Get only the first most suitable value for the PR2 register
PR2= Fosc./(4*fpwm*presc)-1  % PR2 Register
PR2_=PR2(PR2-fix(PR2)==0)(1) 

presc=presc(PR2_==PR2)

PR2=PR2_


% PWM ON time
ton=dc*Tosc*presc;
% PWM duty cycle 0 to 1
DC_=ton/Tpwm  ;  
DC_(DC_>1)= 100;  % Mask the invalid duty cycle
DC=DC_(DC_<=1);   % Cut the duty cycle value > 1 
Vpwm=DC*V;	  % PWM voltage 

% Select only the valid values to the  CCPRxL:CCPxCON
dcc=dc(DC_!=100);
dccmax=max(dcc)  % Maximum value of PWM duty cycle register
DCmax=max(DC)	 % Maximum allowed Duty Cycle




fprintf('\n\nDuty cycle Table\n')
fprintf('CCPRxL:CCPxCON\tDuty Cycle\tPWM Voltage\n')
[ dcc' DC' Vpwm'];



fpwmMax= Fosc/4
fpwmMin= Fosc/(4*256*16)




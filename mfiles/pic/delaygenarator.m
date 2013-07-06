function [] = delays (delay,clock,timer)
%	
%        delaygenerator (delay,Prescale,clock,arch=0,mcu='pic') 
%
%  Generate delay routine for PIC 8 bit microcontrollers
%
%   Parameters
%   delay: Delay time in    uS
%   clock: Clock Frequency MHZ
%   arch : 0 Default
%
%
disp('Instruction time')
Tins= 	4/clock     
disp('Numbers of instructions to perform the delay')
N =  round(delay/Tins)     
disp('Error')
err= delay - N*Tins






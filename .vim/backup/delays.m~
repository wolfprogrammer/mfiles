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

program_name ()
%Debug
%delay=1e6 % 1 seg
%clock=4 % MHZ



N8bits = 2^8
N16bits = 2^16


disp('Instruction time')
Tins= 	4/clock     
disp('Numbers of instructions to perform the delay')
N =  round(delay/Tins)     
disp('Error')
err= delay - N*Tins

opt=menu('Choose one delay generator method','Using 16 bit clock','Using 08 bit clock','Using 8 bit register','Using time interrupt');

switch opt 
case 1
	if( N < N16bits)
		Noverflow=N16bits-N
	else
		Ncycles=N/N16bits
		
                XX=0:(65535);

		sam_=inf;
		
		for n=1:256;
		       ticks= (65536-XX)*n   ;
                       samm=abs(N-ticks) ;
		       sam=min(samm)     ;
		       
		       if( sam_>sam) 
			       sam_=sam             ;
			       NN=n                 ;
			       X=XX(samm==sam)      ;
		       end

		       
		endfor    

		sam_
		NN
		X

		fprintf('timer16=0; timer16= ON \nfor(u=%d;u;u--)\ntimer16=%d\nwhile(!time16)\nend\n',256-NN,X)


		

	endif
case 2
otherwise

endswitch






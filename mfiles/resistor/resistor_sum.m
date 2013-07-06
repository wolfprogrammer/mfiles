#!/usr/bin/octave
#	resistor_sum
#
#   Calculate two serie resistor to match the given value
#  in the given specifications 
#
#   This programa must be invocated in : resistor.m
#
#R=789

#RES = RE12    ;

R1=RES        ;
R2= R- R1     ;

R1=R1(R2>0)   ;
R2=R2(R2>0)   ;
RR2= R2;

for k=1:length(R2)            ;
	k                    ;
	ERR= abs( ( R2(k)-RES))/R2(k)*100;
	err= min(ERR)          ;
	RBB= RES(ERR==err)     ;
	RBB=RBB(1)             ;#Get only the 1st value
	R2(k)=RBB               ;
end

RSUM = R1+R2                    ;
ERRR= abs(R-RSUM)/R*100         ;
errr=min(ERRR)                  ;
R2=R2(ERRR==errr)              ;
R1=R1(ERRR==errr)              ;

fprintf('R= R1+R2 (serie)  (-)--R1-.-R2--(+)\n')
fprintf('R1\tR2\n')
#[ R1_ R2_ ]

rsum=0;

%for k=1:length(R2)
	%resistor_print(R1(k))
	%fprintf('\t')
	%resistor_print(R2(k))
	%fprintf('\n')
%endfor

resistor_print(R1(1))
fprintf('\t')
resistor_print(R2(1))
fprintf('\n') 


errr


#	Calculates the resistors for the voltage 
# divisor
#

E12MAX= 1*MEGA;
RE12_ = [ 10 12 15 18 22 27 33 39 47 56 68 82 ];
RE12= [];              
 
for k=-1:6
	RE12 = [RE12 RE12_.*10^k ] ;
endfor

RE12=RE12(RE12<= E12MAX);
RE12=RE12';                         



# Enter with input voltage
Vi = 12
# Enter with the output voltage
Vo = 3

# Resistor ratio R1/R2
rat = Vi/Vo-1

RB = RE12
RA= round(rat*RB)










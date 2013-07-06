function  V = adc2V(counts,Vr=5,bits=10)
%
%   Returns the Input voltage of ADC given the adc value
%
%   V = adc2V(counts,Vr2=5,Vr1=0,bits=10) 
%
%   adc: ADC value
%   Vr2: Voltage reference 	 	: 5V default
%   bits: Number of bits of ADC bits	: 10 bits
%
%   V: ADC input voltage
%

maxcounts=2^bits;
maxcount=2^bits-1;
if(counts>maxcount) error('Overflow Error'); end

V= Vr/maxcounts*counts;








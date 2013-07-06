function counts = v2adc(voltage,Vr=5,bits=10)
%
%   Returns the adc value 
%
%   v2adc(voltage,Vr=5,bits=10) 
%
%
%

if( voltage > Vr) error('Overflow Error');   end

maxcounts=2^bits;
counts= round(voltage/Vr*maxcounts);

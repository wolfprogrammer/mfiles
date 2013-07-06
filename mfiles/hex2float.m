function F= hex2float(hx)
%  
%  Converte uma string de numero hexa decimal 
% em float IEEE 754 - 32 bits
%
%
V= hex2dec(hx)
sig= bitget(V,31)
sig

if(sig==1)  
	sig=-1 
else
	sig=1

end

sig

EX=bitshift(V,-23)

mantissa=bitand(V,2^23-1)




%    	     testserial.m
%  
%   Testa modulo serial
%
%

pkg load instrument-control
 
 
s1 = serial("/dev/ttyUSB0", 19200) 

# Flush input and output buffers
srl_flush(s1) 

while(true)
	data=char(srl_read(s1,1))
#        fprintf('%c',char(data))

endwhile

 
srl_close(s0) # Closes and releases file descriptor 


function [] = resistor_print(R)


#disp(R) ;

k=0     ;
flag=0  ;

while( (k<=7) && (flag!=1))
	factor = 10^k    ;
	if( R < factor )
#		disp('OK');
		m=k-1    ;
		flag=1   ;
	end
	k=k+1;
endwhile


if( (m>=1) && (m<=2))
	fprintf('%dR',R)  ;

endif


if( (m>=3) && (m<=5) )
	A1=floor(R/1000)        ;
	A2= mod(R,1000)/100     ;
	if(A2!=0)
		fprintf('%dK%d',A1,A2)  ;
	else
		fprintf('%dK',A1)       ;
	end
endif
 
if   (m==6)
	A1=floor(R/1e6)        ;
	fprintf('%dM',A1)      ;
endif                    

# disp(m)

endfunction

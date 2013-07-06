 %    Testa algoritmo para imprimir numero de 16 bits em hexadecimal
 %

 NUM= 6715
 NUMhx=dec2hex(NUM)
 X=NUM
 F=15
 E=14
 D=13
 C=12
 B=11
 A=10

 ascii = @ (a) fprintf('%c\n',a)


 tmp=X
 c0= bitand(X,F)

 if(c0<10)
	  ascii(c0+'0')
else 
         ascii(c0-10+'A')
endif
 
 # c0=dec2hex(c0)

 tmp=  bitshift(tmp,-4)
 c1= bitand(tmp,F)
 c1=dec2hex(c1)

 tmp=  bitshift(tmp,-4)
 c2= bitand(tmp,F)
 c2=dec2hex(c2)
  
 tmp=  bitshift(tmp,-4)
 c3= bitand(tmp,F)
 c3=dec2hex(c3)


 

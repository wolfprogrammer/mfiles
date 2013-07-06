
us=1e-6 ;
ms=1e-3 ;


fclk= input("Entre com o clock em MHZ : ");
Td=  input("Entre com tempo de atraso (delay) em seg :");
fclk=fclk*1e6;

A= [ 1 2 3 4 5 6] ;
A=10.^A  ;

Tcy=4/fclk  ;

Nd=Td/Tcy ;

N=Nd./A ;
N((N>256) | (N<=1))= -1 ;
F=max(N) ;

f=find(N==F) ;

fprintf("Rotina de delay :\n\n") 

switch f
	case 1
	printf('delay10tcy(%d);',F)

	case 2
	printf('delay100tcy(%d);',F)
	
	case 3
	printf('delay1ktcy(%d);',F)

	case 4
	printf('delay10ktcy(%d);',F)

	case 5
	printf('delay100ktcy(%d);',F)

	case 6
	printf('delay1mtcy(%d);',F)
	
	otherwise

endswitch

disp('')
disp('')


#include <stdio.h>


typedef unsigned int   u8;
typedef unsigned long  u32;


u32 hx;
float FL;
int sig;
int mantissa , expp;

void main(){

	printf("Entre com um valor em HEXADECIMAL\n");
	hx=0x3C480000;

	printf("\n%d",hx);

	sig= hx & (2<<31);

	printf("\n%d",sig);

	mantissa= (2<<8-1) & 145 ;
	printf("\n%d",mantissa);


	expp=hx>>23;

	printf("\n%d ",expp);




}

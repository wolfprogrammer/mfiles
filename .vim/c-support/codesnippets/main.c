
/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Testes com o microcontrolador PIC18F4550
 *
 *        Version:  1.0
 *        Created:  08/26/2012 02:55:43 PM
 *       Revision:  none
 *       Compiler:  sdcc
 *
 *         Author:  Caio Rodrigues 
 *        Company:  
 *
 * =====================================================================================
 */




#include <pic18fregs.h>
#include <pic16/pic18f4550.h>

#define  pic18f4550
#include "default.h"


//	 Configurations
//
//    Cristal de 4MHZ
//    Clock  de 48 MHZ
//    Sem Watch Dog Timer
//
code char __at __CONFIG1L  conf1 =  0x0;
code char __at __CONFIG1H  conf2 =  0xE;
code char __at __CONFIG2L  conf3 =  0x18;
code char __at __CONFIG2H  conf4 =  0x0;
code char __at __CONFIG3H  conf5 =  0x80;
code char __at __CONFIG4L  conf6 =  0x40;
code char __at __CONFIG5L  conf7 =  0x3;
code char __at __CONFIG5H  conf8 =  0x40;
code char __at __CONFIG6L  conf9 =  0x3;
code char __at __CONFIG6H  conf10 =  0x60;
code char __at __CONFIG7L  conf11 =  0x3;
code char __at __CONFIG7H  conf12 =  0x40;
/**/




	/////////////////////////////////////////////
	//                MAIN                     //
	/////////////////////////////////////////////

void main(){
 
 
 
 
/* ---------- Main Loop ------------ */
	LOOP{
	



	} 
/*---------- End Of Main Loop ------ */


} // End of Main




	
	// *************  function_name()  *****************
	// 						   
	//  Description:                                   
	//  
	//  Input:
	//
	//
	//  Output:
	//
	// *************************************************



 	/////////////////////////////////////////////
	//               END OF FILE               //
	/////////////////////////////////////////////
 

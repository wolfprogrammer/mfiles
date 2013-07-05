/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Leitor de temperatura
 *	
 *	  Device:   PIC18F4550
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





//#define  pic18f4550
#include <pic18fregs.h>
#include "pic16/pic18f4550.h"

#include "default.h"
#include "registers.h"
#include "delay.h"

//#define   FCLK_HZ 48000000        // System clock       HZ
//#define   INTS_HZ (FLCK_HZ/4)     // Instruction clock  HZ


//--------------------------------------
//	 CONFIGURATION BITS	       //
//-------------------------------------//
ROM char __at __CONFIG1L  conf1 =  0x00;   	// Primary Oscillator XTAL No USB
ROM char __at __CONFIG1H  conf2 =  0x00; 	// IESO=0 FCMEN=0 XT ( Only Use External Oscillator )
ROM char __at __CONFIG2L  conf3 =  0x1E;        // 
ROM char __at __CONFIG2H  conf4 =  0x00;        //  WDT OFF
ROM char __at __CONFIG3H  conf5 =  0x10;	//  Sem MCLR e sem PBADEN=1
ROM char __at __CONFIG4L  conf6 =  0x80; 	//  XINST disabled 
//  Code protection :  No code protection
ROM char __at __CONFIG5L  conf7 =  0xFF;
ROM char __at __CONFIG5H  conf8 =  0xFF;
ROM char __at __CONFIG6L  conf9 =  0xFF;
ROM char __at __CONFIG6H  conf10 = 0xFF;
ROM char __at __CONFIG7L  conf11 = 0xFF;
ROM char __at __CONFIG7H  conf12 = 0xFF;

void delay500ms();



void setup(){
                   //xxx
    	//   OSCCON|= INTERNAL_OSCILLATOR | INTOS_8MHZ;
	OSCCON|= PRIMARY_OSCILLATOR ; 
	TRISD=0X00;
	LATD=0X01;

	TRISB=0X00;
	LATB=0XF0;

}


/////////////////////////////////////////////
//                MAIN                     //
/////////////////////////////////////////////
void main(){

	// --------  VARIABLES -------//





	// ----------  Main Code ----------//
	setup();
	

        /// ddddd   sdas
	//----++      dfsdfx
      // 133
    
 
 
	/* ---------- Main Loop ------------ */
	LOOP{


		LATD=0xF0;
		delay500ms();
		LATD=0X0F;
		delay500ms();
             



	} 
	/*---------- End Of Main Loop ------ */


} // End of Main



 	/////////////////////////////////////////////
	//               END OF FILE               //
	/////////////////////////////////////////////
 



# 	Calcula timer 0 do PIC mcu
#
#  Timer0 16 bits 
#  Sem prescaler
#
#  Calcula interrupt do timer0
#
clc 
clear all

#ENTRADA
Fclk= 48  # Clock em MHZ
Ft= 10	  # Frquencia da interrupt em kHz


#-------------#
VMAX=65535 # Max 16 bit value

Fclk=Fclk*1e6 # Mhz
Fcy=Fclk/4
Tclk=1/Fclk
Tcy=1/Fcy
Ft=Ft*1e3

TMR0=65535-Fcy/Ft








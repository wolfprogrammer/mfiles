#	Calculos do resistor shunt
#
#

R_=0.02 # ohm

# Amostras de tensão
V = [10.3 10.2 10.1 10.0 9.8 10.4 10.1 9.6 ]*1e-3
V= mean(V)

# Amostras de corrent
I = [ 0.96 0.95 0.92 0.91 0.94 0.93 0.92 ] 
I= mean(I)

R= V/I



duty=input('Entre com duty cycle: ')

dutybin=dec2bin(duty)
dutyhex=dec2hex(duty)

CCP1RL=bitshift(duty,-2)

tmp=bitand(duty,3)
tmp= bitshift(tmp,4)
tmphex=dec2hex(tmp)




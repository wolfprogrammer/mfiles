
%dbstop('project',50);  Comando para dubugar arquivo m


%	Projeto de conversor BUCK
% Para sistema MPPT
%
%	A fazer
%  1. Projetar o divisor de tensão com mínima perda de potencia para 5V
%  2. Selecionar diodo adequado e verificar efeito de diodo
%  3. Selecionar Capacitor Ok
%  4. Selecionar Indutor e ver qual o padrão de mercado
%  5. Projetar aplificador do resistor shunt
%
%  2. Comprar um resistor shunt 
%
%

uH=1e-6;
uF=1e-6;



Vin=12.66	 	% V Tensão de entrada do conversor buck
L=470*1e-6
H=3.3*1e-3

#Vo=6    	% V tensão de saída da bateria
f=20	% kHz Frequência de chaveamento


#ri=10 	% Ripple de corrente em %
#rv=1    % Ripple de tensão em %



%---------------------%
%  Cálculos
%

f=f*1000;
% Mínima corrente para haver modo CCM
#Iomin=0.25*(Vin-Vo)/(2*L*f)
Iomin=Vin/(8*L*f)
Rmax= 4*L*f
 

%ri=ri/100
%rv=rv/100
%Io=Pmax/Vo % Corrente de saída

%di=ri*Io       % Ondulação de corrente
%dv=rv*Vo       % Ondulação de tensão

%IL=Io

%ILmax=IL+di/2
%ILmin=IL-di/2

%D1=Vo/Vin1
%D2=Vo/Vin2
%Dmin=min(D1,D2)




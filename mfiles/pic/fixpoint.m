%
%
%
%
%
%--------------  Entrada -------------%

format bank

% ADC
Nbits=10 
adcmax=2^Nbits-1
Nadc=2^Nbits


% Variaveis 
A1=21 	   % Volts  Valor maximo tensão painel
A2=14 	   % Volts  Valor maximo tensão bateria
A3= 2 	   % Amps - Valor maximo da corrente
A1r=0.1    % V      Resolução de A1
A2r=0.1    % V  	     ....A2
A3r=0.001   % A                ...A3

A  = [ A1 A2 A3]
Ar = [ A1r A2r A3r]


disp('Valores sugeridos para o número de bits do ponto fixo');
Mp= log(A)/log(2)       % Número de bits da parte inteira
Np= -log(Ar)/log(2)      % Número de bits da parte fracionaria
Mp=max(Mp)
Np=max(Np)
Mp=ceil(Mp)
Np=ceil(Np)
N=Np+Mp

disp('Fatores de conversão do ADC para ponto fixo');
Fs= A/adcmax*2^Np
FF=Fs-round(Fs)

disp('Recalculo usando variaveis de 16 bits');
Np=20
Mp=12
Fs= A/adcmax*2^Np


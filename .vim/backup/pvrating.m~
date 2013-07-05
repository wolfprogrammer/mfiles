function  pvrating( module , Ta=20 ,G=0.8 )
%{
	usage:  pvrating(PV,T,G)

	module	: Estrutura que representa os dados do painel
	Ta 	: Temperatura Ambiente  [ºC]
	G 	: Irradiação 	          [ kW/m2]


	Default: T=20ºC e G=0.8  Tcel=NOCT

	----------------------------------------------

	Determina de modo aproximado as características
	do painel solar 


	Cálcula:

	FF= Fill Factor / Fator de forma
        FF = (Imp.Vmp)/(Isc.Voc)

        Rmp(STC): Vmp/Imp


	Voc(T)
	Isc(T)
	Pm(T) 


%}


Voc = module.Voc 
Isc = module.Isc 
Vmp = module.Vmp 
Imp = module.Imp 
Pm   = module.Pm
avoc = module.avoc 
aisc = module.aisc 
apm  = module.apm 
NOCT = module.NOCT 


FF  = Imp*Vmp/(Isc*Voc)
Rmp = Vmp/Imp


% Temperatura da celula
Tc=Ta + (NOCT-20)/0.8*G

Isc_T=Isc*G*(1+aisc*(Tc-25))
Voc_T=Voc*G*(1+avoc*(Tc-25))
Pm_T= Pm*G*(1+apm*(Tc-25))







#Voc_NOCT= Voc*(

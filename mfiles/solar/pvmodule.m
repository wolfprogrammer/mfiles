function module=pvmodule(pvfile)
%{
   Retorna os dados de um painel solar 
   armazenado em um arquivo texto 
   com a seguinte extrutura
   
   pvfile= arquivo com as caracteristicas do módulo

   -------- msx60i-kiocera.txt ---------

   manufacture = "Kiocera"
   model = "msx60i"
   ref =   "STC"	    % Condição de teste
   Voc=45.9                 % Volts
   Isc= 14.5                % Amps
   Vmp= 17                  % Amps
   Imp= 19                  % Amps
   Pm=18.93                 % Watts
   avoc = nan               % %/ºC
   aisc = nan               % %/ºC
   apm  = nan               % %/ºC
   NOCT= nan                % ºC
   Ac= nan		    % m2       Area do painel 


%}


fid=fopen(pvfile,'r');

while ~feof(fid)
		line=fgetl(fid);
		eval(line)
end
%endwhile


%module = { manufacture  model Voc Isc Vmp Imp Pm avoc aisc apm NOCT } ;

module.manufacture = manufacture      ;
module.model = model                  ;
module.ref = ref                      ;
module.Voc = Voc                      ;
module.Isc = Isc                      ;
module.Vmp = Vmp                      ;
module.Imp = Imp                      ;
module.Pm= Pm
module.avoc = avoc/100                ;
module.aisc = aisc/100                ;
module.apm =   apm/100                ;
module.NOCT = NOCT                    ;


fclose(fid);  

end

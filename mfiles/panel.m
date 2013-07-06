function []= pvcreate ()
%{
Cria Variavel Com parâmetros do  Modulo Fotovoltaico

uso: PV=pvcreate()

%}

manufacture=input('Manufacture:','s');
model=input('Model:','s');
Voc= input("Voc [A]:");
Isc= input("Isc [A]:");

pvmoduel=[manufacture, model, Voc, Isc]



end
%endfunction







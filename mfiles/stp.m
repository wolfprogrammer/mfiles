function VARS =stp(fnamem)
%{
	stp(fname) 
Cria relatório de cálculo de um script
fname : nomde do script fname.m


%}


%fname="/tmp/tmpoctave"

clc 
home

fname=strcat(fnamem,".m")
fname2="/tmp/vars";


fid=fopen(fname,'r')
format short
statett=0;

while ~feof(fid)
		
		line=fgetl(fid);
		% Não imprime linha que tem 'disp'
	
		switch statett
			
		%-----------------------------------------------------
		case 0	% Procede normalmente
		
		
		fff_1 =length( strfind(line,'disp'))==0 & length( strfind(line,'printf'))==0;
		
		if(fff_1) disp(line);  end
		
		if(  length(strfind(line,'*{'))>0 )   statett=1; end
		
		eval(line);
		
		%--------------------------------------------------
		case 1	% Ignora bloco de comentários  com  %{ e %}
		
		if(  length(strfind(line,'*}'))>0 )   statett=0; end
		
		otherwise
		endswitch %endswitch
		
		
		
		
		%disp(""); 
endwhile
%endwhile



fclose(fid);

clear line fname;

save(fname2);
VARS=load(fname2);
unlink(fname2);        % Apaga o arquivo temporario


% Imprime todas variaveis no contexto da funcao
disp('------------------ Resultados ------------------')
vars;

end

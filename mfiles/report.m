function VARS=report(fnamem)
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
pprint_=false;

idxx=1;

if( !exist('DEBUG') ) DEBUG=false;
%DEBUG=true;

while ~feof(fid)
	
		
		
		line=fgetl(fid);
		% Não imprime linha que tem 'disp'
		
		if(DEBUG)
		disp('----------------')
		printf( 'idxx= %d\n',idxx);
		printf( 'line= %s\n',line);
		statett
		pprint_
		idxx++;
		disp('----------------')
		endif
		
		
	
		switch statett
			
		%-----------------------------------------------------
		case 0	% Procede normalmente
		
		

			if( strmatch('disp',line) | strmatch('printf',line))
				eval(line);
			elseif( strmatch('*{',line) ) 
				statett=1
			else
				disp(line)
				eval(line)
					
			end
		
			
		
		%--------------------------------------------------
		case 1	% Ignora bloco de comentários  com  %{ e %}
		
		if(  strmatch('%}',line) )   statett=0; end
		
		
		
		%--------------------------------------------------
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
%vars;

end

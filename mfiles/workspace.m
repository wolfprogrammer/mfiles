%		workspace.m
%
% 	Visualiza todas as variaveis no espaço de trabalho
%   com seus respectivos valores.
%
%   Se DVIEW==true  as variaveis são mostradas em planilha.
%  para facilitar a vizualização.
%
% C	0.000052
% Cmin	0.000052
% D	0.705882
% D1	0.294118
%
%
%  $ Para visualizar os dados em planilha instale o gnumeric
%  $sudo apt-get install gnumeric
%
% Flags de configuração



format long;
save '/tmp/varlist.mat';

names=who;
nn1=length(names);
         

if(!exist('DVIEW')) DVIEW=false;  endif


if(DVIEW==true)
	fname='/tmp/vartable';
	fid=fopen(fname,'w');
endif


for idx=1:nn1
	
	vname=cell2mat(names(idx,1));
	vvalue=eval(vname);                      
	if( isa(vvalue,'double') & strcmp(typeinfo(vvalue),'scalar') )
		if( abs(vvalue)>1)
			fprintf('\t%s\t\t%3.3f\n',vname,vvalue);

			if(DVIEW==true)  fprintf(fid,'\t%s\t\t%3.3f\n',vname,vvalue);  end

		else
			fprintf('\t%s\t\t%3.3g\n',vname,vvalue);

			if(DVIEW==true)  fprintf(fid,'\t%s\t\t%3.3g\n',vname,vvalue);  end

		end
		
	else
	endif
	
endfor

% Fecha arquivo
if(DVIEW==true) 
	fclose(fid);   % Fecha arquivo
	
	cmd=sprintf('gnumeric %s --no-splash --no-warnings  &',fname);
	system(cmd);
	
%	unlink fname;  % Apaga arquivo
endif



clear names   vnames   vvalue idx nn1 

load '/tmp/varlist.mat';

format short;

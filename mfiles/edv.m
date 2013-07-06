
function [MM] = edv(M)
%  edv(M)
%
%  Visualiza matriz externamente ao octave em planilha
%  M- matriz nxm
%
%  Se M==-1 cria a matriz é carregada após salvar
%
%  FLAG:
%

fname='/tmp/octave_matrix.cvs'                   ;
save("-ascii",fname,'M')               	     ;

if( M== -1)
        cmd=sprintf('gnumeric %s --no-splash --no-warnings  ',fname);
	system(cmd);
        MM=load(fname);
else
	cmd=sprintf('gnumeric %s --no-splash --no-warnings  &',fname);
	system(cmd);
	MM=[];
endif 



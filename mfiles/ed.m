function VARS =ed(flag=0)
%{

ed(flag=0)

flag=0 : Executa sem imprimir
    =1 : Imprime lina e executa


Abre janela em que é possível copiar e colar código
e executálo.



%}

%fname="/tmp/tmpoctave"
fname=tmpnam();
fname2="/tmp/vars";

cmd=sprintf("leafpad %s",fname);
system(cmd);

fid=fopen(fname,'r');

while ~feof(fid)
		line=fgetl(fid);
			if (flag)
			disp(line);
			end
		
		eval(line);
		

end
%endwhile



fclose(fid);
unlink(fname);

clear line fid fname;

save(fname2);
VARS=load(fname2);
unlink(fname2);        % Apaga o arquivo temporario

end

end

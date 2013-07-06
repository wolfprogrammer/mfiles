function [] = plt(x,y)
%
%  plt(x,y)
%
%  Plot data usinfg matplotlib
%
%  INPUT
%  x,y : vectors of size N
%

n1=size(x)    ;
n2=size(y)    ;

if n1!=n2
	error("Vectors of different sizes");
end

if n1(1)<n1(2)
      %  disp("ONE");
	xy=[x' y']     ;
else
        xy=[x y]      ;
end

% Cria arquivo temporário em TMP
%fname=tmpnam()  
fname="/tmp/plot.txt"                   ;
save("-ascii",fname,"xy")               ;
cmd="python $HOME/mfiles/plt.py &"                   ;
system(cmd)                             ;


end

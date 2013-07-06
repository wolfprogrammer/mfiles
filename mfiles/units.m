%    STANDARD UNITS OF SI ANF CONSTANTS
%
%


%  Constants
%

% Gravity
gravity=9.80665 % m/s2
g0=gravity

% Gas constant
R0=8.3145 % J/K mol





%-------------------------------------%

%	Tempo
sec=1                ;
minn=60*sec          ;
hour=60*minn         ;

%------------------------------------% 

% Transforma de graus para radianos
d2r = @(d) pi/180*d ;

% Transforma de radianos para graus
r2d = @(r) 180/pi*r ;

% Converte de radianos/seg para Hertz
rads2hz= @(w) w/(2*pi)  ;

% Converte de Hertz para radianos/seg
hz2rads= @(f)  f/(2*pi) ;

% Rpm para radianos/seg 
rpm2rads= @(rpm) rpm*2*pi/60

% Rpm para Hz
rpm2hz= @(rpm) rpm/60


%----------------------------------%
%	FATORES DE CONVERSÃO	   %
%----------------------------------%

in2mm= 25.4  ;
mm2in= 1/25.4;



%--------------------------------%
%
%














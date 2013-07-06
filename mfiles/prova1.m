
%%
% Configuracoes
clc
clear

d2=1
a2=1

a3=-1

d4=1

d6=1


T=[ 0 , 1 , 0 ,-1 ;  0 , 0, -1 , 0.232 ; -1 ,0 ,0 , 1.866 ; 0, 0 ,0 , 1]


ARM=  -1 % Braco esquerdo
ELBOW= 1 % Cotovelo p/ cima 
WRIST=-1 % Punho p/ cima

r2d=180/pi

n=T(1:3,1)
s=T(1:3,2)
a=T(1:3,3)
p=T(1:3,4)

nx=n(1)
ny=n(2)
nz=n(3)

sx=s(1)
sy=s(2)
sz=s(3)

ax=a(1)
ay=a(2)
az=a(3)

% Centro do Punho

pc=p-a*d6

px=pc(1)
py=pc(2)
pz=pc(3)

% Angulo Teta1
disp "\n\nAngulo teta1"

R=sqrt(px^2+py^2)
R1=R
r=sqrt(R^2-d2^2)

Y=-ARM*py*r-px*d2
X=-ARM*px*r+py*d2
q1=atand2(Y,X)


%   Angulo Teta2
disp "\n\nAngulo teta2"

R=sqrt(px^2+py^2+pz^2-d2^2)
R2=R
Calpha=-pz/R
Salpha=- ARM*r/R
alpha=atand2(Salpha,Calpha)

Cbeta= (a2^2+R^2-(d4^2+a3^2))/(2*a2*R)
Sbeta= sqrt(1-Cbeta^2)
beta=atand2(Sbeta,Cbeta)

K=ARM*ELBOW
q2=alpha+K*beta


%   Angulo Teta3
disp "\n\nAngulo teta3"

R=R2

Cphi=(a2^2+(d4^2+a3^2)- R^2)/(2*a2*sqrt(d4^2+a3^2))
Sphi=ARM*ELBOW*sqrt(1-Cphi^2)
phi=atand2(Sphi,Cphi)

Sbeta=d4/sqrt(d4^2+a3^2)
Cbeta=abs(a3)/sqrt(d4^2+a3^2)
beta=atand2(Sbeta,Cbeta)

q3=phi-beta


%  Angulo Teta4
%
disp "\n\nAngulo teta4"

% Constantes auxiliares
C1=cosd(q1)
S1=sind(q1)
C23=cosd(q2+q3)
S23=sind(q2+q3)


R03=zeros(3,3); % incia vetor Z3 3x1
% Coluna 1
R03(1,1)= C1*C23 ;
R03(2,1)= S1*C23 ;
R03(3,1)= S23    ;
% Coluna 2
R03(1,2)= S1;
R03(2,2)= C1;
R03(3,2)= 0 ;
% Coluna 3
R03(1,3)= C1*S23;
R03(2,3)= S1*S23;
R03(3,3)= C23;
disp('R03=')
disp(R03)


X3=R03(1:3,1)
Y3=R03(1:3,2)
Z3=R03(1:3,3)

%  Z4= (Z3xa)/||Z3xa||
v=cross(Z3,a)   %  v= Z3xa
absv=norm(v)     %  absv=abs(v)
Z4=v/absv    

% omega = s.Z4
omega=dot(s,Z4)

M=WRIST*sign(omega)

Y=M*( C1*ay-S1*ax )
X=M*( C1*C23*ax +  S1*C23*ay - S23*az)
q4=atand2(Y,X)

C4=cosd(q4)
S4=sind(q4)


%   Angulo Teta5
disp "\n\nAngulo teta5"

Y= (C1*C23*C4-S1*S4)*ax + (S1*C23*C4+ C1*S4)*ay - C4*S23*az
X= (C1*S23*ax + S1*S23*ay+ C23*az)
q5=atand2(Y,X)


%   Angulo Teta6
disp "\n\nAngulo teta6"
Y= (-S1*C4 -C1*C23*S4)*nx + (C1*C4 - S1*C23*S4)*ny  + (S4*S23)*nz
X= (-S1*C4 -C1*C23*S4)*sx + (C1*C4 - S1*C23*S4)*sy  + (S4*S23)*sz
q6=atand2(Y,X)


%----------------------------
disp "\n\nAngulos nas juntas"
q=[ q1 ; q2 ; q4 ; q4 ; q5 ; q6];
q1
q2
q3
q4
q5
q6



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%               Testes			     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
printf("Testes\n\n");



%--------------------------------------
%     Teste com a tabela do denavit

    % alpha d a
M= [ -90 , 0 , 0 ;  \
       0 , 1,  1 ;  \
      90 , 0, -1 ;  \
     -90 , 1,  0 ;  \
      90 , 0,  0 ;  \
       0 , 1,  0 ]


Ht=fkin(q,M)

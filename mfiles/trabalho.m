clc()
K1=10.0
C1=7.0
M1=9

K2=2
C2=5
M2=5

K3=2
C3=6
M3=4

K4=4
C4=10


%   [M].Xdd+[C].Xd+[K].X=F(t)
%     X=( x1 x2 x3)t
%     Xd=(x1' x2' x3')
%     F(t)= (u 0 0 )
%   
M=[ M1 0 0 ; 0 M2 0 ; 0 0 M3]
K=[ K1+K2, -K2 , 0; -K2 , K3+K2, -K3; 0, -K3, K3+K4]
C=[ C1+C2, -C2 , 0; -C2 , C3+C2, -C3; 0, -C3, C3+C4]

% Frequênias naturais sao:
%   w^2.M.X.=K.X        u=X e  q=sqrt(w)
%   M.X.q=K.X     ==>   qMu=K.u 
%   Tu=q.u      T=M^-1.K   
%
%   q: Autovalor
%   X: Autovetor

% Frequências naturais
q=eig(inv(M)*K)
wn=sqrt(q)



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       ESTADO DE ESPAÇOS                            %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

A= [ 0 , 0 , 0 , 1 , 0 , 0 ; 
     0 , 0,  0 , 0,  1,  0 ;
     0 , 0,  0 , 0,  0,  1 ;
     -(K1+K2)/M1, K2/M1, 0 , -(C1+C2)/M1, C2/M1 ,0 ;
     K2/M2 , -(K2+K3)/M2, K3/M2 , C2/M2, -(C2+C3)/M2, C3/M2;
     0 , K3/M3, -(K4+K3)/M3 ,0 , C3/M3, -(C4+C3)/M3]
 
 B=[0, 0, 0, 1/M1 ,0, 0]'
 
 C=eye(6) 
 
 D=[0 0 0 0 0 0]'
  
  [num,den]=ss2tf(A,B,C,D,1)
  %T=tf(num,den)
  %TX1=T(1,:)
  %TX2=T(2,:)
  %TX3=T(3,:)
  
   X1=tf(num(1,:),den)
   figure(1)
   impulse(X1)
   
   figure(2)
   step(X1)
   
   
   
   
%  num2= [ 0   -0.0000    0.1111    0.6889    1.0333    0.5889    0.1111 ]
%  den2= [ 1.0000    7.5333   18.3444   23.3000   17.7667    7.3778    1.2000 ]
  
  %roots(den2)
  
%T2=tf(num2,den2)

figure(3)
t=0:0.1:10
ww=0.56
u=sin(0.56*t)
y=lsim(X1,u,t)
plot(t,u)
plot(t,y)


num=1;
den=[1 10 20];
Kp=300;

H=tf(num,den)
u=tf(1,1)
Hcl=feedback(Kp*H,u)
#t=0:0.01:2;
#step(numCL, denCL,t)
M = 1;
K = 10;
B = 2;
num = 1;
den = [M B K];
sys = tf(num,den);

step(sys)

function Q= muldp(Q1,Q2);

QQ.V=Q1.V*Q2.V;
QQ.q=Q1.q*Q2.q/2^(Q1.n);
QQ.m=Q1.m;
QQ.n=Q1.n;
Q=QQ;

 

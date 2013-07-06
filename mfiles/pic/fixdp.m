function Q = fixdp(V,m=8,n=8)

q=round(V*2^n);

if(q>(2^(m+n)-1))
   	warning("Overflow");
end

QQ.q=q;
QQ.V=V;
QQ.m=m;
QQ.n=n;

Q=QQ;




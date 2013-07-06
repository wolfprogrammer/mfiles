#!/usr/bin/python
from pylab import *

data=genfromtxt("/tmp/plot.txt")
x=data[:,0]
y=data[:,1]
plot(x,y)
grid()
show()



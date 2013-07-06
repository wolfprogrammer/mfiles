
all:	Terminal.o WishHandler.o Octawrap.o wrap.o HistoryCommands.o Pthread.o WishMonitor.o
	g++ -Wall -g -o wrap Pthread.o Octawrap.o HistoryCommands.o Terminal.o WishHandler.o wrap.o WishMonitor.o 

WishMonitor.o:	WishMonitor.C WishMonitor.H
	g++ -Wall -g -c -o WishMonitor.o WishMonitor.C

Pthread.o:	Pthread.C Pthread.H
	g++ -Wall -g -c -o Pthread.o Pthread.C

Terminal.o:	Terminal.C Terminal.H
	g++ -Wall -g -c -o Terminal.o Terminal.C

WishHandler.o:	WishHandler.C WishHandler.H
	g++ -Wall -g -c -o WishHandler.o WishHandler.C

Octawrap.o:	Octawrap.C Octawrap.H
	g++ -Wall -g -c -o Octawrap.o Octawrap.C

HistoryCommands.o:	HistoryCommands.C HistoryCommands.H
	g++ -Wall -g -c -o HistoryCommands.o HistoryCommands.C

wrap.o:		wrap.C
	g++ -Wall -g -c -o wrap.o wrap.C

clean:	
	rm *.o
	rm wrap
	rm *~



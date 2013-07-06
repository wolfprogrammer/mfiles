#define TRUE 1
#define FALSE 0

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <signal.h>
#include <wait.h>
#include <iostream>

using namespace std;

#include "Pthread.H"
#include "HistoryCommands.H"
#include "WishHandler.H"
#include "Terminal.H"
#include "Octawrap.H"
#include "WishMonitor.H"


   WishHandler wishhand1;
   WishHandler wishhand2;
   WishHandler wishhand3;
   WishHandler wishhand4;
   WishHandler* activeWish;


WishMonitor::WishMonitor()
{
   wishhand1.run(); // We launch the two threads for wish
   wishhand2.run();
   wishhand3.run();
   wishhand4.run();
   activeWish = &wishhand1;
   // activeWish->displayWidget("uicontrol('style','canvas')");     
}


void WishMonitor::end()
{
     wishhand1.end(); 
     wishhand2.end();
     wishhand3.end();
     wishhand4.end();
}

void WishMonitor::process(char* buffer)
{
   while (*buffer==' ') buffer++;     // we remove initial spaces
                                      // we trust we will not be called with empty buffer
   if (strncmp(buffer,"figure",6)==0) 
   {
        char* cifer=&buffer[7];
        buffer[8]=0;
        int number = atoi(cifer);
        if (number>0) {
                  if (number==1) activeWish = &wishhand1;
                  if (number==2) activeWish = &wishhand2;
                  if (number==3) activeWish = &wishhand3;
                  if (number==4) activeWish = &wishhand4;
                  cout << "Activate " << number << endl;
                  activeWish->showEmpty();
        }
   }
   else if (strncmp(buffer,"close",5)==0) 
   {
        activeWish->restart();
   }
   else if (strncmp(buffer,"uicontrol",9)==0)
   {
        activeWish->displayWidget(buffer);
        printf("\n");
   }
}




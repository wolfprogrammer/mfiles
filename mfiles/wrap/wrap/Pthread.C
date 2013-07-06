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
#include "WishHandler.H"


void Pthread::run()
{
      sonpid=fork();
      if (sonpid==0) {
         close(toSon[1]);      // we will create a bidirectional communication for signal
         close(fromSon[0]);    // interchange. Used here only to request end of son.
         this->execute();
         while(1);             // anyway, execute should never return
      }
      close(toSon[0]);
      close(fromSon[1]);
}

void Pthread::end()
{
      cout << "stopping process: " << sonpid << endl;
      char c = '\n';
      write(toSon[1],&c,1);      // To send this code through this channel is a stop request
      int status;                // the children has to catch it and die properly
      waitpid(sonpid,&status,0); // we catch its exit code
}

void Pthread::restart()
{
      cout << "restarting process: " << sonpid << endl;
      char c = 'A';
      write(toSon[1],&c,1);      // To send this code through this channel is a stop request
      int status;                // the children has to catch it and die properly
      waitpid(sonpid,&status,0); // we catch its exit code
}



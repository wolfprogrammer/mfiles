
// Resumen: Por estetica, el prog no esta en el constructor si no en run, pero no es un thread.
// lanzo 3 wishhandlers. 
// Creo un canal bidireccional con un futuro octavehandler.
// forko y ejecuto el octave en segundo plano
// lanzo console2octave
// lanzo octave2console
// espero a que console2octave muera. Termina si el user lo pide.
// mato los demas hilos (octave2console y los wishhandlers)

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

#include "WishMonitor.H"
#include "Pthread.H"
#include "HistoryCommands.H"
#include "WishHandler.H"
#include "Terminal.H"
#include "Octawrap.H"

// Wish monitor. En el constructor crea los wish pero aun no los muestra
WishMonitor wm;    


Octawrap::Octawrap()
{
}

void Octawrap::run()
{
     term.echo_off();
     term.set_charmode();
 
     int toOctave[2]; // the pipe call give us two pipes
     pipe(toOctave);  // with two fds each one
     int fromOctave[2];
     pipe(fromOctave); 

     // the user has the first word
     term.allowEditing();

     int fdoct = fork();
     if (fdoct==0)
     {
        close(toOctave[1]);      // usaremos f2s para leer de el (0)
        close(fromOctave[0]);    // y s2f para escribirle al padre (1)
   
        close(0);
        close(1);
        dup2(toOctave[0],0);     // el fd0, nuestra in, vendra del father.
        dup2(fromOctave[1],1);   // y nuestra out, ira al father

        char *const av[]={"octave","-i", (char *)0};
        execv("/usr/bin/octave",av);
        while(1);                // if we type exit octave will die. Just in case can reach this.
     }

     close(toOctave[0]);   // usaremos f2s para escribirle al hijo (1)
     close(fromOctave[1]); // y s2f para leer (0)

     // this is for speaking with octave
     int fd1 = fork();
     if (fd1==0) console2octave(toOctave);       // this will copy console output to octave continously
     int fd2=fork();                   
     if (fd2==0) octave2console(fromOctave);     // return from octave a la shell
     int rcode;
 
     // WARNING: now it also will die the octave monitor thread, (pid=fdoct), at the same
     // time that console2octave dies.

     waitpid(fd1,&rcode,0);      // only the first process can finish (console2octave)
                                 // because it is who identifies the quit command
                                 // it doesnt kill wishhandlers with it. We will do it here.

     kill(fd2,1);                // we kill the other thread with SIGUP
     waitpid(fd2,&rcode,0);

     // we will kill octave in a nice way
     char buffer[256];
     char c;
     strcpy(buffer,"exit");
     for (int f=0;f<4;f++) write(toOctave[1],&(buffer[f]),1);
     c='\n';
     write(toOctave[1],&c,1);      // we send the exit command to octave and it will die
     waitpid(fdoct,&rcode,0);
     // kill(fdoct,1);
     // waitpid(fdoct,&rcode,0);

     // and finally we kill the wishMonitor
     wm.end();

     printf("Exiting ...\n");

     // we leave the terminal as it where before
     term.restore();
}


   int isPrompt(char* buffer)
   {
      int len = strlen(buffer);
      return ((buffer[0]=='o')&&(buffer[len-1]=='>'));
   }

   void Octawrap::octave2console(int* fromOctave)
   {
        char c;
        char laststring[256];         // We will record here the prompt, which starts by octave
        laststring[0]=0;              // and we activate the edition when it comes
        int len=0;
        while(1)                      // Copying from octave;
        {
            read(fromOctave[0],&c,1); // este suele dormir
            laststring[len]=c;
            if (len<255) len++;
            laststring[len]=0;
            write(1,&c,1);
            if (isPrompt(laststring)) 
            {
                  term.setPrompt(laststring);
                  term.allowEditing();
                  laststring[0]=0;
                  len=0;
            }
            if (c=='\n')
            {
               laststring[0]=0;
               len=0;
            }
        }
   }

   int Octawrap::analizebuffer(char* buffer, int* toOctave) 
   // we will return 1 if buffer has to be written to Octave
   {
         int result = 1;      //  1 = is a octave valid command
                              //  0 = it was a graphic command, and we report it.
                              // -1 = end request

         // first, we remove the spaces at left.
         while ((*buffer==' ')&&(*buffer!=0)) buffer++; 
 
         if (strncmp(buffer,"quit",4)==0) result=-1;
         else if (strncmp(buffer,"exit",4)==0) result=-1;
         else if (strncmp(buffer,"figure",6)==0) result=0;
         else if (strncmp(buffer,"close",5)==0) result=0;
         else if (strncmp(buffer,"uicontrol",9)==0) result=0;

         return result;
   }

   void Octawrap::console2octave(int* toOctave) // we copy forever the console input to octave
   {
        char c;
        static char buffer[1024];
        char end = 0;
        while(!end)                             // copying to octave
        {
           int size=term.readstring(buffer,1024);
           int typeinstruction;
           //  0 = instruction for wish, already handled
           //  1 = instruction for octave. Maybe trash.
           // -1 = end requested
           typeinstruction=analizebuffer(buffer,toOctave);
           if (typeinstruction==1)
           {
              printf("\n");
              for (int f=0;f<size;f++) write(toOctave[1],&(buffer[f]),1);
              c='\n';
              write(toOctave[1],&c,1);      // to Octave
           }
           else if (typeinstruction==-1)
           {
              end=1;                        // we will exit the loop next time
           }
           else if ((typeinstruction)==0)   // to the active Wish
           {
              wm.process(buffer);           // we send the command as a string
              char c = '\n';
              write(toOctave[1],&c,1);      // give me a new prompt
           }
        }
        exit(EXIT_SUCCESS);
   }


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

int wishpid;

WishHandler::WishHandler()
{
    for (int f=0;f<4;f++) numvar[f]='0';
    apagado=TRUE;
    numvar[3]=0;         // null terminator for making a string out of it

    pipe(toWish);        // with two fds each one
    pipe(fromWish);      // that makes four
                         // all the procedures will have a copy of them
    apagado=FALSE;
} 

void WishHandler::showEmpty()
{
    char buffer[]="\n";
    write(toWish[1],buffer,strlen(buffer));
}


void WishHandler::emptyAndHide()
{
   cout << "here we should kill the pid=" << wishpid << endl;
   // kill(wishpid,1); // SIG_TERM
   cout << "and that would fuck the system" << endl;
   //  char buffer[]="\n";
   //  write(toWish[1],buffer,strlen(buffer));
}

void WishHandler::execute()
{                                     // is expected never to finish
      int handlerpid;
      char caracter;
      bool weHaveFinished = 0;
      fd_set myset;

      while(!weHaveFinished)
      {
         // here we wait until somebody try to speak with the wish, and then we launch it.
         FD_ZERO(&myset);
         FD_SET(toWish[0],&myset);
         FD_SET(toSon[0],&myset);
         select(toWish[0]+toSon[0]+1,&myset,NULL,NULL,NULL);

         // First we launch a thread for taking care of killing requests.
         int pidtemp = fork();
         if (pidtemp==0) 
         { 
            char c;
            read(toSon[0],&c,1);
            if (c=='\n') exit(0);
            else exit(-1);            // they want just to close the window
         }

         wishpid = fork();
         if (wishpid==0) {
            close(toWish[1]);         // usaremos f2s para leer de el (0)
            close(fromWish[0]);       // y s2f para escribirle al padre (1)
            close(0);                 // desconecto de la consola
            close(1);                 // idem
            dup2(toWish[0],0);        // el fd0, nuestra in, vendra del father.
            dup2(fromWish[1],1);      // y nuestra out, ira al father
            char *const av[]={"wish", (char *)0};
            execv("/usr/bin/wish",av);
            while(1);
         } 

         handlerpid=fork();
         if (handlerpid==0) 
         {
               // No puedo cerrar estos dos fuera, o los wish que respawnee no los heredaran
               close(fromWish[1]);
               close(toWish[0]);
  
               // ponerme aqui a escuchar sus sandeces en background
               // en cambio para hablar con el lo hare desde otro metodo
               char buffer[1024];
               buffer[0]=0;
               int indice=0;
               while(read(fromWish[0],&caracter,1))
               {
                  if (caracter=='\n') 
                  {
                     buffer[indice]=0;
                     printf("recibido callback: %c\n",buffer[0]);
                     printf("recibido callback: %c\n",buffer[1]);
                     if (strncmp(buffer+1,"close",5)==0) {
                         exit(0);
                     }
                     indice=0;
                     buffer[indice]=0;
                  }
                  else {
                     buffer[indice]=caracter;
                     indice++;
                  }
               }
               while(1); // this shouldnt be reached
         }

         // anyone of the previous three threads can die. We will check which one dies first and
         // we will kill the others, according to how big the problem was.

         int result;
         pid_t muerto = wait(&result);

         if (muerto==handlerpid) {
            kill(wishpid,1);
            kill(pidtemp,1);
         }
         else if (muerto==wishpid) {
            kill(handlerpid,1);
            kill(pidtemp,1);
            printf("Window closed. Restarting.\n");
         }
         else if (muerto==pidtemp) {
            kill(handlerpid,1);
            kill(wishpid,1);
            if (result==0) weHaveFinished=1;
         }
         wait(&result);
         wait(&result);
     }   // until finished
     cout << "The wishandler thread has died." << endl;
     // now we send a code to the father, that waits for it.
     exit(0);
} // execute

void WishHandler::displayWidget(char* buffer)
{
    char* buffer3;
    buffer3 = translate(buffer,numvar);
    // we will get empty string if the buffer is not valid.
    if (buffer3[0]!=0) 
    {
       write(toWish[1],buffer3,strlen(buffer3));
       char buffer4 [256];
       strcpy(buffer4,"pack .b"); 
       strcat (buffer4,numvar);
       strcat (buffer4,"\n");
       write(toWish[1],buffer4,strlen(buffer4));
       sig(numvar);
    }
}

void WishHandler::sig(char* cad) 
{
      cad[2]++;
      if (cad[2]>'9') {
           cad[2]=0;
           cad[1]++;
      }
      if (cad[1]>'9') {
           cad[1]=0; 
           cad[0]++;
      }
      if (cad[0]>'9') cad[0]=0;
}


char* WishHandler::translate(char* cad, char* numvar)
{
      static char result[255];
      result[0]=0;

      char buffer1 [255];
      char buffer2 [255];
      char* fw = buffer1;
      char* rest = buffer2;

      char* parameters [50]; // 50 parameters maximum
 
      strcpy(fw,cad);
      fw=firstword(fw,'(');
      limpiar(fw);
   
      strcpy(rest,cad);
      rest=getrest(rest);
      limpiafin(rest);
      rest=quitaparent(rest);

      char* ptr=rest;
      int i = 0;
      parameters[0]=ptr;
      i++;
      int status=0; // 0 fuera de comillas
                    // 1 dentro de comillas


      while (*ptr!=0) {
         while (((*ptr!=',')||(status==1))&&(*ptr!=0)) {
            if (*ptr=='\'') {
                if (status==0) status=1;
                else status=0;
            }
            ptr++;
         }
         if (*ptr!=0) {
            *ptr=0;
            ptr++;
            parameters[i]=ptr;
            i++; // this will count how many parameters are
         }
      }
      char* orderedparameters[25];
   
      int f;
      for (f=0;f<10;f++) orderedparameters[f]=0; // null
 
      // here we put each parameter in its place
      for (f=0;f<i;f++) {
         if ((f%2)==0) {
            // printf("parametro %i: %s = ",f/2,parameters[f]);
            if (!strcasecmp(parameters[f],"'style'")) 
               orderedparameters[0]=parameters[f+1]; // style
            if (!strcasecmp(parameters[f],"'position'")) 
               orderedparameters[1]=parameters[f+1]; // position
            if (!strcasecmp(parameters[f],"'callback'")) 
               orderedparameters[2]=parameters[f+1]; // position
            if (!strcasecmp(parameters[f],"'string'")) 
               orderedparameters[3]=parameters[f+1]; // text of a label or button
         }
      }
 
      // The order of the parameters is
      // 1 = style
      // 2 = position
      // 3 = command (callback associated)
      // 4 = string, para labels
  
      if (i>1) 
      {
         printf("parameters: %i\n",i);
         if (!strcasecmp(orderedparameters[0],"'pushbutton'")) { // style
            strcat(result,"button .b");
            strcat(result,numvar);
            strcat(result," ");
         }
         if (!strcasecmp(orderedparameters[0],"'text'")) {      // style
            strcat(result,"label .b");                          // also labels .bxxx
            strcat(result,numvar);
            strcat(result," ");
         }
         if (!strcasecmp(orderedparameters[0],"'canvas'")) {    // a new style
            strcat(result,"canvas .b");                         // will be used for plots
            strcat(result,numvar);
            strcat(result," ");
            strcat(result,"-background white");
            strcat(result," ");
         }
         if (orderedparameters[1]) {             // position
            printf("%s\n",orderedparameters[1]);
            // this parameter start and finish with []
            // it will have four numbers separated by spaces. Only the two last interest.
            strcat(result,"-width 10 ");
            strcat(result,"-heigh 5 ");
            // the two first numbers can be used to sort. 
            // we should start writting widgets starting by the higher file
            // and among those with the same file, first the lower column
         }
         if (orderedparameters[2]) {             // there is a callback
            strcat(result,"-command {puts {");
            strcat(result,orderedparameters[2]);
            strcat(result,"}} ");
         }
         if (orderedparameters[3]) {             // there is a text in the label or button
            strcat(result,"-text ");
            strcat(result,orderedparameters[3]);
         }
 
         strcat(result,"\n");
      }
      return result;
} // WishHandler::Translate

   char* WishHandler::getrest(char* cad)
   {
      while ((*cad!='(')&&(*cad!=0)) cad++;
      return cad;
   }

   char* WishHandler::limpiafin(char* cad)
   {
      char* oldcad;
      while (*cad!=0) cad++;
      cad--;
      while ((*cad==' ')||(*cad=='\n')) {
         *cad=0;
         cad--;
      }
      if ((*cad)==';') *cad=0;
      return oldcad;
   }


   char* WishHandler::firstword(char* cad, char c)
   {
      char* ptr = cad;
      while (((*cad)!=0)&&((*cad)!=c)) cad++;
      *cad=0;
      return ptr;
   }

   char* WishHandler::limpiar(char* cad)
   {
      while ((*cad==' ')||(*cad=='\n')) cad++;
      char* ptr = cad;
       while (*ptr!=0) ptr++;
      ptr--;
      while ((*ptr==' ')||(*ptr=='\n')) {
           *ptr=0;
           ptr--;
      }
      return cad;
   }


   char* WishHandler::quitaparent(char* cad)
   {
      if (*cad!='(') printf("Syntax error: parenthesis expected\n");
      if (cad[strlen(cad)-1]!=')') printf("closing parenthesis expected\n");
      cad[strlen(cad)-1]=0;
      return ++cad;
   }

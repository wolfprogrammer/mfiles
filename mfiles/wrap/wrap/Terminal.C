
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



   Terminal::Terminal()
   {
      tcgetattr(0,&oldsettings);
      hc = new HistoryCommands();
      prompt[0]=0;
      editingMode=0;
   }
   
   void Terminal::restore(void) {
      tcsetattr(0,TCSANOW,&oldsettings);
      return;
   }

   void Terminal::set_stringmode(void) {
      tcsetattr(0,TCSANOW,&stored_settings);
      return;
   }

   void Terminal::setPrompt(char* newPrompt)
   {
      strcpy(prompt,newPrompt);
      for (unsigned int f=0;f<strlen(prompt);f++)
      {
         char d=0x1b;
         write(1,&d,1);
         write(1,"[1D",3);            // move cursor once backwards
      }
      cout << prompt << flush;
   }

   void Terminal::echo_off(void)
   {
     tcgetattr(0,&stored_settings);
     new_settings = stored_settings;
     new_settings.c_lflag &= (~ECHO);
     tcsetattr(0,TCSANOW,&new_settings);
     return;
   }

   void Terminal::echo_on(void) 
   {
     tcgetattr(0,&stored_settings);
     new_settings = stored_settings;
     new_settings.c_lflag &= (ECHO);
     tcsetattr(0,TCSANOW,&new_settings);
     return;
   }

   void Terminal::set_charmode(void)
   {
      tcgetattr(0,&stored_settings);
      new_settings = stored_settings;

      /* Disable canonical mode, and set buffer size to 1 byte */
      new_settings.c_lflag &= (~ICANON);
      new_settings.c_cc[VTIME] = 0;
      new_settings.c_cc[VMIN] = 1;
  
      tcsetattr(0,TCSANOW,&new_settings);
      return;
  }

   void Terminal::blockEditing()    // called by the user pushing enter
   {
      //editingMode = 0;
      //printf("Edition Off\n");
   }

   void Terminal::allowEditing()    // called by octave, sending back a string.
   {
      //while (editingMode==1) {
         //cout << "." << flush;
         //sleep(1);
      //}
      //editingMode = 1;
      //printf("Edition On\n");
   }

   void Terminal::refresh(char* buffer, int count, char* temp, int counttemp, int inipos)
   {
     char commandline [256];

     inipos += strlen(prompt);        // me da igual lo que tuviera antes

     for(int f=0;f<inipos;f++)        // reset cursor
     { 
         char d=0x1b;
         write(1,&d,1);
         write(1,"[1D",3);            // move cursor once backwards
     } 

     // write(1,buffer,count);        // first part of the string
     memcpy(commandline,buffer,count);
              
     char* ptr=temp+counttemp-1;      // second part of the string
     for (int f=0;f<counttemp;f++) 
     {
        // write(1,ptr--,1);
        commandline[count+f]=*ptr;
        ptr--;
     }
     commandline[count+counttemp]=0;  // null terminator
     cout << commandline << flush;

     char d=0x20;
     write(1,&d,1);                   // in case we delete something
     for(int f=0;f<=counttemp;f++)    // reset cursor
     {
        char d=0x1b;
        write(1,&d,1);
        write(1,"[1D",3);
     }
     hc->report(commandline);
   }

bool empty (char* buffer)
{
  while (buffer[0]==' ') buffer++;
  return(buffer[0]==0);
}

int Terminal::readstring(char* buffer, int size)
{
  char c = 0;
  char temp[1024];      // for editing purposes
  int counttemp = 0;    // we reset the second buffer
  read(0,&c,1);         // leemos el primero de la cadena
  int count=0;          // we reset buffer
  int especial=0;

  while (c!='\n')       // Enter will indicate end of input by the user
  {
     buffer[count]=c;
     if (especial) 
     {
        if (c=='D') 
        {
           if ((count>0)&&(counttemp<1024))
           {
              c=0x1b;
              write(1,&c,1);
              write(1,"[1D",3);
              count--;                       // pop
              temp[counttemp]=buffer[count]; // push
              counttemp++;
           }
        }
        else if (c=='C') {
           if ((count<1024)&&(counttemp>0))
           {
              c=0x1b;
              write(1,&c,1);
              write(1,"[1C",3);
              counttemp--;
              buffer[count]=temp[counttemp]; // push
              count++;                       // pop
           }
        }
        else if (c=='A')                     // upwards scroll key
        {
           while (count>0) {
              count--;
              refresh(buffer,count,temp,counttemp,count+1);
           }

           *buffer=0;
           hc->pushBackCurrent();
           hc->getCurrentCommand(buffer);
           *temp=0;
           count=strlen(buffer);
           counttemp=0;
           refresh(buffer,count,temp,counttemp,0);
        }
        else if (c=='B') 
        {                   // downwards scroll key
           while (count>0) 
           {
              count--;
              refresh(buffer,count,temp,counttemp,count+1);
           }

           *buffer=0;
           hc->pushFrontCurrent();
           hc->getCurrentCommand(buffer);
           *temp=0;
           count=strlen(buffer);
           counttemp=0;
           refresh(buffer,count,temp,counttemp,0);
        }
        else if (c=='3')                     // delete next
        {
            if (counttemp>0) counttemp--;
            read(1,&c,1);
            refresh(buffer,count,temp,counttemp,count);
        }
        // else printf("Not understood: %c\n",c);
        especial=0;
     }
     else if (c==27) {
          especial=1;
          read(1,&c,1);                     // it will be a double byte char.
     }
     else if (c<32) {                       // weird caracter ignored
     }
     else {
        if (c==127)                         // delete previous
        {
            if (count>0) {
                count--;
                refresh(buffer,count,temp,counttemp,count+1);
            }
        }
        else {
            buffer[count]=c;
            if (count<size) count++; 
            refresh(buffer,count,temp,counttemp,count-1);
        }
     }
     read(0,&c,1);  // next one
  } // end of editing part

  // here we have to copy temp onto buffer.
  int f;

  for (f=counttemp-1;f>=0;f--) 
  {
     buffer[count]=temp[f];
     count++;
  }
  buffer[count] = 0;

  if (!empty(buffer)) hc->post(); //insert(buffer);
  printf("\n");

  return count; // size without null terminator
}


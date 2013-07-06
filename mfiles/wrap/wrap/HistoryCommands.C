
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
#include "HistoryCommands.H"
#include "Terminal.H"
#include "Octawrap.H"

#define BUFFERLENGTH 256
#define HISTORYLENGTH 10
char buffers [HISTORYLENGTH][BUFFERLENGTH];


int numcommands;
int current;

HistoryCommands::HistoryCommands()
{
   for (int f=0;f<10;f++) buffers[f][0]=0;
   numcommands = 0;
}

void HistoryCommands::reset()
{
   for (int f=0;f<10;f++) buffers[f][0]=0;
   numcommands = 0;
}

HistoryCommands::~HistoryCommands()
{
}

void HistoryCommands::insert(char* command)
{
   for (int f=numcommands;f>0;f--) {
      strncpy(buffers[f],buffers[f-1],255);
   }
   strncpy(buffers[0],command,255);
   numcommands++;
   current = 0;
}

void HistoryCommands::getCurrentCommand(char* extbuf)
{
   extbuf[0]=0;
   char* punt;
   if (current<numcommands) 
   {
      punt = buffers[current];
      strncpy(extbuf,punt,255);
   }
}

void HistoryCommands::pushBackCurrent()
{
   if (current<9) current++;
}

void HistoryCommands::pushFrontCurrent()
{
   if (current>0) current--;
}

void HistoryCommands::post()
{
   for (int f=numcommands;f>0;f--) {
      strncpy(buffers[f],buffers[f-1],255);
   }
   buffers[0][0] = 0;     // we prepare an empty entry for the next edition
   if (numcommands<9) numcommands++;
   current = 0;
}

void HistoryCommands::report(char* command)
{
   strncpy(buffers[0],command,255);
   // printf("Post: %s\n",buffers[0]);
}




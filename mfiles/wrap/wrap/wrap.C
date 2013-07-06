
/* ****************************************************************************
 * Octave wrapper - a matlab graphic compatibility layer for octave
 * (c) 2003 Juan Garcia de Arboleya
 * This program is licensed under the BSD license.
 * You can find a complete copy of the license at www.gnu.org.
 * ****************************************************************************
 */

#define TRUE 1
#define FALSE 0

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <signal.h>
#include <wait.h>

using namespace std;

#include "Pthread.H"
#include "HistoryCommands.H"
#include "WishHandler.H"
#include "Terminal.H"
#include "Octawrap.H"

// ============================ MAIN ==================================

int main(int argc, char** argv) 
{
   Octawrap myprog;
   myprog.run();
   return 0;
}


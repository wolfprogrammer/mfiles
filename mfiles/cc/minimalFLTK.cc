/**
   @file      minimalFLTK.cc
   @author    Mitch Richling <http://www.mitchr.me/>
   @Copyright Copyright 2003 by Mitch Richling.  All rights reserved.
   @brief     Minimal FLTK program@EOL
   @Keywords  fltk minimal
   @Std       C++98

*/

#include <FL/Fl.h>              /* FLTK main       FLTK  */
#include <FL/Fl_Window.h>       /* FLTK window     FLTK  */

#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdlib.h>             /* Standard Lib    ISOC  */

int main() {
  Fl_Window win(500, 500, "Hello World!");
  win.show();
  return Fl::run();
}

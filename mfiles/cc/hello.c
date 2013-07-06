#include <octave/oct.h>
#include<stdio.h>
     
     DEFUN_DLD (hello, args, nargout,
       "Hello World Help String")
     {
  
printf("Hello world!!!!!!!!!\n");
    
     }


OCTAWRAP, version Alpha-6
=========================


1.- HOW TO BUILD AND INSTALL
============================

First of all, uncompress the tar file that you have downloaded (as you already did, or you wouldnt be reading this).

From the version alpha6, the support for the threads is done through an external library (c++Threads). I have included it into my project as it is. You will have to compile it before compiling the rest of the project. You can also go to the sourceforge page of the project and download from there the last version.
 
First thing you have to compile is this library. Go under the "threads" directory and type ./configure and later "make". A file called "libthreads.a" should appear in the threads/threads/ directory. The rest of the files are not important for this project.

Now come back to the directory where you uncompresed the tar file and simply type "make". The makefile is quite simple. Sorry. I can not better.

With this, you have just finished the building process. For installation, just copy the recently build file "wrap" onto a directory that is in your path, like /usr/bin.

REQUIRES: Octave and Wish properly installed in /usr/bin.
========


2.- FUNCIONALITIES
==================

Presently, very few. It handles properly (i.e. similar to matlab) the construction and destruction of windows (try figure and uicontrol commands) and it also handles transparently the communications with octave (any octave command should work)

When it comes to handle widgets, only buttons (pushbuttons) and labels are working. The system for handling the callbacks is working properly (try to install a callback on a button and to push it. The system will report that it gets the call, but is still unable to handle it)

The editing routines are working more or less but without history of commands. I will add it as soon as possible.

New things!!!
=============

I have abandon the c++Threads library, and now I do everything with processes. The reason is that the library is still not widely used, and I do not want the users to have to install and compile aditional programs.

Anyway, this is a client and performance issues shouldnt be a problem.

If somebody wants to port the program to this or other thread library, of course is very welcomed. 



3- KNOWN ERRORS
===============

Well, programs dying or not dying cannot be seen. Anyway, for sure there are still millions of errors.


4.- LICENSE
===========

By now, BSD, but maybe I will switch to GPL soon. Be prepared.


I hope you will find the project usefull,


Juan Garcia de Arboleya
2003



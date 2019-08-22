// header file for sh

#ifndef HEADER
#define HEADER

// including common standard library header files

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/times.h>
#include<sys/wait.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

// header file for colors 

#include"colorsfile.h"

// functions prototypes designed for sh

extern int strcnt ( char *str );
extern char** cmdarr ( const char *carray );
extern int cmdexc1 ( char **list );

// globals variables

int count;

#endif
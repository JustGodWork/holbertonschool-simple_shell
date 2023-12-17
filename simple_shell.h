#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define EXIT_CHILD 3 /* Exit status for child process */
#define DEBUG 1 /* 0 = false, 1 = true */

#include "libraries.h"
#include "debug.h"

/* exit_handler.c */
int exit_handler(char *command);

#endif

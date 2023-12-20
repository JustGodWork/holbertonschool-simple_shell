#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define EXIT_BUILT_IN 3 /* Exit status for built-in command */
#define EXIT_CMD_NOTFOUND 127 /* Exit status for child process */
#define DEBUG 0 /* 0 = false, 1 = true */

#include "debug.h"

/* GLOBAL ENVIRON */
extern char **environ;

void execute_command(char *command, char *program_name, int command_count);

#endif

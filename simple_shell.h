#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_ARGS_SIZE 1024 /* Max number of arguments */
#define EXIT_BUILT_IN 3 /* Exit status for built-in command */
#define EXIT_EXEC_FAILURE 127 /* Exit status for child process */
#define DEBUG 0 /* 0 = false, 1 = true */

#include "libraries.h"
#include "debug.h"

/* GLOBAL ENVIRON */
extern char **environ;

char **split_args(char *command);
void free_args(char **args);
int execute(char *command, char **args, char *program_name);
char *clear_command(char *command);

#endif

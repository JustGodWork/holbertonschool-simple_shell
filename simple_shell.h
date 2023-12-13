#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

typedef struct built_in_command
{
	char *name;
	int (*handle)();
} built_in_command_s;

/* built_in_commands.c */
int (*get_built_in_command(char *command))();
int built_in_exit();

/* execute_command.c */
void execute_command(char **command);

#endif

#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include "libraries.h"

#define EXIT_BUILT_IN 3 /* Exit status for built-in command */
#define EXIT_CMD_NOTFOUND 127 /* Exit status for child process */
#define DEBUG 0 /* 0 = false, 1 = true */

/* print_debug.c */
int print_debug(const char *format, ...);

/* Usage in get_built_in_command.c */
/**
 * struct built_in_command - Struct for built-in commands
 * @name: The name of the command
 * @handle: The function to handle the command
 */
typedef struct built_in_command
{
	char *name;
	int (*handle)();
} built_in_command_s;

/* built_in_commands.c */
int (*get_built_in_command(char *command))();
int built_in_exit(void);

/* loop_listener.c */
void loop_listener(
	int *user_input,
	int *status,
	char **envp,
	char *program_name
);

/* execute_command.c */
void execute_command(
	char **command,
	char **envp,
	int *status,
	char *program_name
);

/* get_command_path.c */
char *get_command_path(char *command, char **envp);

#endif

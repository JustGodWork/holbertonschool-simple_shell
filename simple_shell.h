#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_ARGS_SIZE 1024 /* Max number of arguments */
#define EXIT_BUILT_IN 3 /* Exit status for built-in command */
#define EXIT_EXEC_FAILURE 127 /* Exit status for child process */
#define DEBUG 0 /* 0 = false, 1 = true */

#include "libraries.h"
#include "debug.h"

/* STRUCTS */
/**
 * struct builtin - Struct builtin
 * @name: Name of the builtin
 * @handle: Function pointer to the builtin
 */
typedef struct builtin
{
	char *name;
	int (*handle)(char **args, int status, char *input, char **env);
} builtin_t;

char **split_args(char *command);
void free_args(char **args);
int execute(char *command, char **args, char *program_name, char **env);
char *clear_command(char *command);
int is_path(char *command);
char *scan_dir(char *command, char **env);
int is_builtin(char **args, int status, char *input, char **env);

#endif

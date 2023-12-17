#include "simple_shell.h"

/**
 * get_built_in_command - Get handle
 * associated with command name
 * @command: Command to find handle
 * Return: handle function
 */
int (*get_built_in_command(char *command))()
{
	int i;
	built_in_command_s commands[] = {
		{"exit", built_in_exit},
		{NULL, NULL}
	};

	for (i = 0; commands[i].name != NULL; i++)
		if (strcmp(command, commands[i].name) == 0)
			return (commands[i].handle);

	return (NULL);
}

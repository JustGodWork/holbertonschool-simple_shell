#include "simple_shell.h"

/**
 * exit_handler - Handles the exit command
 * @command: The command string
 * Return: (0) on success, (-1) on fail
 */
int exit_handler(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		info("Command exit called.");
		exit(EXIT_CHILD);
		return (EXIT_SUCCESS);
	};
	return (EXIT_FAILURE);
}

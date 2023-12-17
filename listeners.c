#include "simple_shell.h"

/**
 * eof_listener - Listens for EOF and exits if found
 * @user_input: The user input
 * @interactive: A flag to indicate if the shell is interactive
 * @command: The command to execute
 * Return: (1) if EOF is found, (0) otherwise
*/
int eof_listener(int *user_input, int interactive, char *command)
{
	if (*user_input == EOF)
	{
		if (interactive)
			putchar('\n');
		debug_free(command, "Clearing memory (eof_listener)");
		exit(EXIT_SUCCESS);
		return (1);
	};
	return (0);
}

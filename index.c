#include "simple_shell.h"

/**
 * prompt - Print prompt
 * @interactive: Interactive mode
 * Return: void
 */
void prompt(int interactive)
{
	if (interactive)
		printf("$ ");
}

/**
 * listen_for_eof - Listen for EOF
 * @bytes_read: Bytes read
 * @program_name: Program name
 * @interactive: Interactive mode
 * Return: (0) on success, (1) on fail
 */
int listen_for_eof(ssize_t bytes_read, char *program_name, int interactive)
{
	if (bytes_read == EOF)
	{
		if (feof(stdin))
		{
			if (interactive)
				putchar('\n');
			fflush(stdout);
			return (0);
		};
		perror(program_name);
	};
	return (1);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: An array of strings containing each argument
 * Return: (0) always success
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	ssize_t bytes_read = 0;
	char *command = NULL;
	int command_count = 0;
	size_t command_size = 0;
	char *program_name = argv[0];
	int interactive = isatty(STDIN_FILENO);

	while (bytes_read != EOF)
	{
		prompt(interactive);
		bytes_read = getline(&command, &command_size, stdin);
		if (!listen_for_eof(bytes_read, program_name, interactive))
			break;
		if (strcmp(command, "\n") == 0)
			continue;
		command[bytes_read - 1] = '\0';
		/* if (strcmp(command, "exit") == 0) */
		/*	break; */
		execute_command(command, program_name, command_count);
	};

	dfree(command);
	return (0);
}

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
 * @command: Command
 * @interactive: Interactive mode
 * @status: Exit status
 * Return: void
 */
void listen_for_eof(
	ssize_t bytes_read,
	char *command,
	int interactive,
	int status
)
{
	if (bytes_read == EOF)
	{
		free(command);
		if (interactive)
			putchar('\n');
		exit(status);
	};
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
	char *input = NULL;
	char *command = NULL;
	size_t input_len = 0;
	char *program_name = argv[0];
	int interactive = isatty(STDIN_FILENO);
	char **args = NULL;
	int status = EXIT_SUCCESS;

	while (bytes_read != EOF)
	{
		prompt(interactive);
		bytes_read = getline(&input, &input_len, stdin);
		dinfo("Input received: %s", input);
		listen_for_eof(bytes_read, input, interactive, status);
		command = clear_command(input);
		dinfo("Command cleared: %s", command);
		if (strcmp(command, "\n") == 0)
			continue;
		command[strlen(command) - 1] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			free(input);
			break;
		};
		dinfo("Trying exec: %s", command);
		args = split_args(command);
		status = execute(command, args, program_name);
		free_args(args);
	};

	return (0);
}

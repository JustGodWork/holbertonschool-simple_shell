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
		dinfo("EOF detected.");
		free(command);
		if (interactive)
			putchar('\n');
		exit(status);
	};
}

/**
 * no_args - Check if args is NULL
 * @args: Arguments
 * @input: Command
 * @program_name: Program name
 * Return: 1 if success, 0 if failure
 */
int no_args(char **args, char *input, char *program_name)
{
	if (!args)
	{
		dinfo("Arguments invalid.");
		free(input);
		perror(program_name);
		exit(EXIT_FAILURE);
		return (1);
	};
	return (0);
}

/**
 * invalid_command - Print invalid command
 * @full_command: Full command
 * @program_name: Program name
 * @status: Exit status pointer
 * Return: void
 */
void invalid_command(char *full_command, char *program_name, int *status)
{
	fprintf(stderr, "%s: %s: command not found\n", program_name, full_command);
	*status = EXIT_EXEC_FAILURE;
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: An array of strings containing each argument
 * Description: A simple UNIX command interpreter.
 * Return: (0) always success
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	ssize_t bytes_read = 0;
	char *input = NULL;
	char *full_command = NULL;
	char *tmp_command;
	size_t input_len = 0;
	char *program_name = argv[0];
	int interactive = isatty(STDIN_FILENO);
	char **args;
	int status = EXIT_SUCCESS;

	while (bytes_read != EOF)
	{
		prompt(interactive);
		bytes_read = getline(&input, &input_len, stdin);
		listen_for_eof(bytes_read, input, interactive, status);
		full_command = clear_command(input);
		if (strcmp(full_command, "\n") == 0)
			continue;
		full_command[strlen(full_command) - 1] = '\0';
		args = split_args(full_command);
		if (no_args(args, input, program_name))
			break;
		if (is_builtin(args, status, input))
			continue;
		if (!is_path(args[0]))
		{
			tmp_command = args[0];
			args[0] = scan_dir(args[0]);
			free(tmp_command);
		};
		if (!args[0])
			invalid_command(full_command, program_name, &status);
		else
			status = execute(full_command, args, program_name);
		free_args(args);
	};
	return (0);
}

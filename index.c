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
 * main - Entry point
 * @argc: Number of arguments
 * @argv: An array of strings containing each argument
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
		dinfo("Receiving user input.");
		listen_for_eof(bytes_read, input, interactive, status);
		dinfo("No EOF detected.");
		full_command = clear_command(input);
		dinfo("Cleared command");
		if (strcmp(full_command, "\n") == 0)
			continue;
		dinfo("Command is not a newline character.");
		full_command[strlen(full_command) - 1] = '\0';
		dinfo("Removing newline character.");
		args = split_args(full_command);
		dinfo("Splited args.");
		if (!args)
		{
			dinfo("Args invalid.");
			free(input);
			perror(program_name);
			exit(EXIT_FAILURE);
			break;
		};
		dinfo("Args valid.");
		if (is_builtin(args, status, input))
			continue;
		dinfo("Not a builtin.");
		dinfo("args[0]: %s", args[0]);
		if (!is_path(args[0]))
		{
			tmp_command = args[0];
			args[0] = scan_dir(args[0]);
			free(tmp_command);
		};
		dinfo("Scanned dir.");
		if (!args[0])
		{
			dinfo("Command not found.");
			fprintf(stderr, "%s: %s: command not found\n", program_name, full_command);
			status = EXIT_EXEC_FAILURE;
		}
		else
		{
			dinfo("Trying exec: %s", full_command);
			status = execute(full_command, args, program_name);
		};
		dinfo("Freeing -----");
		free_args(args);
	};

	return (0);
}

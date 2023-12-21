#include "simple_shell.h"

/**
 * clear_command - Clear command
 * @input: Input
 * Return: Command without leading spaces
 */
char *clear_command(char *input)
{
	while (*input == ' ' || *input == '\t')
		input++;
	return (input);
}

/**
 * execute - Execute a command
 * @command: Command
 * @args: Arguments
 * @program_name: Program name
 * @env: Environment variables
 * Return: Exit status
 */
int execute(
	char *command,
	char **args,
	char *program_name,
	char **env
)
{
	pid_t pid;
	int status = EXIT_SUCCESS;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(
				stderr,
				"%s: %s: command not found\n",
				program_name,
				strtok(command, " ")
			);
			exit(EXIT_EXEC_FAILURE);
		};
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		perror("fork failed.");
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	};

	return (status);
}

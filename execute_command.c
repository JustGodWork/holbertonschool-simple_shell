#include "simple_shell.h"

void handle_pid_state(pid_t pid, char *command, char **args)
{
	int status;
	if (pid == -1)
	{
		perror("Error: fork");
		free(command);
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		execve(command, args, NULL);
		perror("Error execve");
		free(command);
		exit(EXIT_FAILURE);
	} else
		wait(&status);
}

/**
 * execute_command - Executes a command
 * @args: An array of strings containing the command and its arguments
 * Return: (0) on success, (-1) on fail
 */
void execute_command(char **command)
{
	pid_t my_pid;
	char *args[2];
	int (*handle)();

	args[0] = *command;
	args[1] = NULL;

	if (*command[0] == '\0')
	{
		free(*command);
		return;
	};

	my_pid = fork();

	handle = get_built_in_command(*command);

	if (handle)
	{
		if (handle() == -1)
			exit(EXIT_FAILURE);
		free(*command);
		return;
	};

	handle_pid_state(my_pid, *command, args);
}

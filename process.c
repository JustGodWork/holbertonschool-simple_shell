#include "simple_shell.h"

/**
 * create_process - Creates a new process
 * @command: The command to execute
 * @envp: An array of strings containing each environment variable
 * @program_name: The name of the program
 * @status: The exit status of the process
 * Return: void
*/
void create_process(
	char *command,
	char **envp,
	char *program_name,
	int *status
)
{
	pid_t child_pid = fork();
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	if (child_pid == -1)
	{
		debug_free(command, "Clearing memory on failure (fork)");
		printf("%s: fork: error\n", program_name);
		*status = EXIT_FAILURE;
		return;
	}
	else if (child_pid == 0)
	{
		if (execve(command, args, envp) == -1)
		{
			debug_free(command, "Clearing memory on fail (execve)");
			perror(program_name);
			exit(EXIT_FAILURE);
			*status = EXIT_FAILURE;
		};
		*status = EXIT_SUCCESS;
		return;
	}
	else
		wait(status);
}

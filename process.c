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
		debug_free(command, "Clearing memory (create_process)");
		perror(program_name);
		exit(EXIT_FAILURE);
		return;
	};
	if (child_pid == 0)
	{
		print_debug(DEBUG_INFO, "Trying execution of command: %s", command);
		if (execve(command, args, envp) == -1)
		{
			debug_free(command, "Clearing memory (create_process)");
			error("Command failed");
			perror(program_name);
			exit(EXIT_FAILURE);
		};
		info("Command executed successfully");
		return;
	};
	wait(status);
}

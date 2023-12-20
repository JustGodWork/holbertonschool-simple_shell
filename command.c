#include "simple_shell.h"

/**
 * execute_command - Execute command
 * @command: Command to execute
 * @program_name: Program name
 * @command_count: Command count
 * Return: void
 */
void execute_command(char *command, char *program_name, int command_count)
{
	pid_t pid;
	int status;
	char *args[2];

	pid = fork();
	(void)command_count;

	if (pid == -1)
		dinfo("Fork invalid"), perror("fork"), exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		/* Child process */
		dinfo("Executing command: %s", command);
		if (execve(command, args, environ) == -1)
			perror(program_name), dfree(command), exit(EXIT_FAILURE);
	}
	else
		/* Parent process */
		waitpid(pid, &status, 0);
}

#include "simple_shell.h"

/**
 * exec_handler - Handle execve
 * @handle: Handle
 * @command: Command to execute
 * @args: Arguments to pass to command
 * @env: Environment variables
 * Return: (0) on success, (-1) on fail
*/
int exec_handler(int (*handle)(), char *command, char **args, char **env)
{
	if (handle)
	{
		print_debug("[Info] exec_handler() -> built-in command: %s", command);
		if (handle() == -1)
		{
			print_debug(
				"[Error] exec_handler() -> built-in command: %s",
				command
			);
			free(command);
			exit(EXIT_FAILURE);
			return (-1);
		};
		print_debug("[Success] exec_handler() -> built-in command: %s", command);
		free(command);
		return (0);
	};
}

/**
 * handle_pid_state - Handle pid state
 * @pid: Process id
 * @command: Command to execute
 * @args: Arguments to pass to command
 * @env: Environment variables
 * Return: void
*/
void handle_pid_state(pid_t pid, int *status, char *command, char **args, char **env, int (*handle)())
{
	print_debug("[Info] handle_pid_state() -> pid: %d", pid);

	if (pid == -1)
	{
		print_debug("[Error] handle_pid_state() -> fork");
		perror("Error: fork");
		free(command);
		exit(EXIT_FAILURE);
		return;
	} else if (pid == 0)
	{
		if (exec_handler(handle, command, args, env))
		{
			free(command);
			return;
		};
		print_debug(
			"[Info] handle_pid_state() -> Executing command: %s",
			command
		);
		execve(command, args, env);
		perror("Error execve");
		free(command);
		return;
	} else
		wait(status);
}

/**
 * execute_command - Executes a command
 * @command: Command to execute
 * @envp: An array of strings containing each environment variable
 * @status: Status of the command
 * the command and its arguments
 * Return: (0) on success, (-1) on fail
 */
void execute_command(char **command, char **envp, int *status)
{
	pid_t my_pid;
	char *args[2];
	int (*handle)();

	args[0] = *command;
	args[1] = NULL;

	if (*command[0] == '\0')
	{
		print_debug("[Info] execute_command() -> Empty command");
		return;
	};

	my_pid = fork();
	handle = get_built_in_command(*command);

	handle_pid_state(my_pid, status,*command, args, envp, handle);
}

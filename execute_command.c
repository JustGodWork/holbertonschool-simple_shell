#include "simple_shell.h"

/**
 * handle_pid_state - Handle pid state
 * @pid: Process id
 * @command: Command to execute
 * @args: Arguments to pass to command
 * @env: Environment variables
 * Return: void
*/
void handle_pid_state(pid_t pid, char *command, char **args, char **env)
{
	int status;

	if (pid == -1)
	{
		print_debug("[Error] handle_pid_state() -> fork");
		perror("Error: fork");
		free(command);
		exit(EXIT_FAILURE);
		return;
	};
	if (pid == 0)
	{
		print_debug(
			"[Info] handle_pid_state() -> Executing command: %s",
			command
		);
		execve(command, args, env);
		perror("Error execve");
		free(command);
		exit(EXIT_FAILURE);
		return;
	};
	wait(&status);
}

/**
 * execute_command - Executes a command
 * @command: Command to execute
 * @envp: An array of strings containing each environment variable
 * the command and its arguments
 * Return: (0) on success, (-1) on fail
 */
void execute_command(char **command, char **envp)
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

	if (handle)
	{
		if (handle() == -1)
		{
			print_debug(
				"[Error] execute_command() -> built-in command: %s",
				*command
			);
			free(*command);
			exit(EXIT_FAILURE);
			return;
		};
		print_debug("[Success] execute_command() -> built-in command: %s", *command);
		free(*command);
		return;
	};

	handle_pid_state(my_pid, *command, args, envp);
}

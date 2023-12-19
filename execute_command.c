#include "simple_shell.h"

/**
 * exec_handler - Handle execve
 * @command: Command to execute
 * Return: (0) on success, (-1) on fail
*/
int exec_handler(char *command)
{
	int (*handle)();

	handle = get_built_in_command(command);

	if (handle)
	{
		print_debug("[Info] exec_handler() -> built-in command: %s", command);
		if (handle() == -1)
		{
			print_debug(
				"[Error] exec_handler() -> built-in command: %s",
				command
			);
			print_debug("exec_handler() -> Clearing memory -1");
			free(command);
			exit(EXIT_FAILURE);
			return (-1);
		};
		print_debug("[Success] exec_handler() -> built-in command: %s", command);
		print_debug("exec_handler() -> Clearing memory 0");
		free(command);
		return (0);
	};
	return (-1);
}

/**
 * fork_success - Handle fork success
 * and execute command
 * @program_name: Program name
 * @command: Command to execute
 * @args: Arguments to pass to command
 * @env: Environment variables
 * Return: void
 */
void fork_success(
	char *program_name,
	char *command,
	char **args,
	char **env
)
{
	char *path;

	if (exec_handler(command) == 0)
	{
		print_debug("fork_success() -> Clearing memory 0");
		free(command);
		return;
	};
	print_debug(
		"[Info] fork_success() -> Executing command: %s",
		command
	);
	path = get_command_path(command);
	if (path)
	{
		if (execve(path, args, env) == -1)
		{
			printf("%s: %s: ", program_name, command);
			perror("\n");
		};
	}
	else
		printf("%s: %s: command not found\n", program_name, command);
}

/**
 * fork_fail - Handle fork failure
 * and execute command
 * @program_name: Program name
 * @command: Command to execute
 * Return: (0) on success, (-1) on fail
 */
void fork_fail(char *program_name, char *command)
{
	print_debug("[Error] handle_pid_state() -> fork");
	print_debug("handle_pid_state() -> Clearing memory");
	free(command);
	perror(program_name);
	exit(EXIT_FAILURE);
}

/**
 * execute_command - Executes a command
 * @command: Command to execute
 * @envp: An array of strings containing each environment variable
 * @status: Status of the command
 * @program_name: Program name
 * the command and its arguments
 * Return: (0) on success, (-1) on fail
 */
void execute_command(
	char **command,
	char **envp,
	int *status,
	char *program_name
)
{
	pid_t pid = fork();
	char *args[2];

	args[0] = *command;
	args[1] = NULL;

	print_debug("[Info] handle_command() -> pid: %d", pid);

	if (pid == -1)
	{
		/* Handle fork failure */
		fork_fail(program_name, *command);
		return;
	}
	else if (pid == 0)
	{
		/* Handle fork success */
		fork_success(program_name, *command, args, envp);
		return;
	};
	wait(status);
}

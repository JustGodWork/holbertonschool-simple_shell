#include "simple_shell.h"

/**
 * listen_for_eof - Listens for EOF and exits if found
 * @user_input: The user input
 * @interactive: A flag to indicate if the shell is interactive
 * @command: The command string
 * Return: void
*/
void listen_for_eof(int *user_input, int interactive, char *command)
{
	if (*user_input == EOF)
	{
		if (interactive)
			putchar('\n');
		debug_free(command, "Freeing memory after EOF");
		exit(EXIT_SUCCESS);
	};
}

/**
 * listen_for_child_stop - Listens for child process stop
 * @status: The status of the child process
 * @command: The command string
 * Return: void
*/
void listen_for_child_stop(int status, char *command)
{
	int exit_status;

	if (WIFEXITED(status))
	{
		info("Child exited");
		exit_status = WEXITSTATUS(status);
		print_debug(DEBUG_SUCCESS, "Child exited with status %d", exit_status);
		if (exit_status != EXIT_CHILD && exit_status != EXIT_SUCCESS)
		{
			debug_free(command, "Freeing memory after child process error");
			exit(exit_status);
			return;
		};
		if (exit_status == EXIT_CHILD)
		{
			exit(EXIT_SUCCESS);
			return;
		};
		debug_free(command, "Freeing memory after child process success");
	};
}

/**
 * handle_child_process - Handles the child process
 * @pid: The process id
 * @command: The command string
 * @args: The arguments array
 * @envp: The environment variables array
 * @program_name: The program name
 * Return: void
*/
void handle_child_process(
	pid_t pid,
	char *command,
	char **args,
	char **envp,
	char *program_name
)
{
	if (pid == 0)
	{
		execve(command, argv, envp);
		printf("%s: command not found\n", program_name);
		debug_free(command, "Freeing memory after execve");
		exit(EXIT_FAILURE);
	};
}

/**
 * handle_child_failure - Handles the child
 * process failure
 * @pid: The process id
 * @command: The command string
 * @status: The status of the child process
 * Return: void
*/
void handle_child_failure(pid_t pid, char *command, int status)
{
	if (pid == -1)
	{
		debug_free(command, "Freeing memory after fork failure");
		perror("fork");
		exit(WEXITSTATUS(status));
	};
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: An array of strings containing each argument
 * @envp: An array of strings containing each environment variable
 * Return: (0) always success
*/
int main(int argc, char **argv, char **envp)
{
	int interactive = isatty(STDIN_FILENO);
	char *program_name = argv[0];
	char *command = NULL;
	size_t command_size = 0;
	int user_input = 0;
	int status = EXIT_SUCCESS;
	pid_t child_pid;

	(void)argc;

	while (user_input != EOF)
	{
		if (interactive)
			printf(DEBUG ? "!$ " : "$ ");

		user_input = getline(&command, &command_size, stdin);

		if (!command)
			printf("%s: getline: allocation error\n", program_name);

		listen_for_eof(&user_input, interactive, command);
		command[user_input - 1] = '\0';

		child_pid = fork();
		handle_child_process(child_pid, command, argv, envp, program_name);
		handle_child_failure(child_pid, command, status);
		wait(&status);
	};

	return (EXIT_SUCCESS);
}

#include "simple_shell.h"

/**
 * handle_exit - Handle exit status
 * @status: The status
 * @command: A pointer to the command
 * Return: void
 */
void handle_exit(int status, char *command)
{
	int exit_status = 0;

	/* Check if child process has exited */
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);

		print_debug("Exit code: %d", exit_status);
		/* Handle exit status */
		if (exit_status != EXIT_SUCCESS)
		{
			print_debug("[Info] handle_exit() -> Child process exited normally");
			print_debug(
				"[Info] handle_exit() -> Child process exited with status: %d",
				exit_status
			);
			print_debug("[Info] handle_exit() -> Clearing memory");
			free(command);
			exit(exit_status);
		};
		print_debug("[Info] handle_exit() -> Clearing memory");
		free(command);
	};
}

/**
 * listen_for_eof - Listen for EOF (End of file)
 * @user_input: A pointer to the user input
 * @command: A pointer to the command
 * @interactive: A flag to indicate if the shell is interactive
 * @status: A pointer to the status
 * Return: void
 */
void listen_for_eof(
	int user_input,
	char *command,
	int interactive,
	int *status
)
{
	if (user_input == EOF)
	{
		print_debug("[Info] listen_for_eof() -> EOF detected");
		print_debug("[Info] listen_for_eof() -> Clearing memory");
		free(command);
		if (interactive)
			putchar('\n');
		if (*status == EXIT_CMD_NOTFOUND)
			exit(EXIT_CMD_NOTFOUND);
		else
			exit(EXIT_SUCCESS);
	};
}

/**
 * input_listener - Listen to user input
 * @user_input: A pointer to the user input
 * @status: A pointer to the status
 * @envp: An array of strings containing each environment variable
 * @program_name: Program name
 * Return: void
 */
void loop_listener(
	int *user_input,
	int *status,
	char **envp,
	char *program_name
)
{
	char *command = NULL;
	size_t command_len = 0;
	int interactive = isatty(STDIN_FILENO);

	/* Print prompt if stdin is a terminal */
	if (interactive)
		printf("%s", DEBUG ? "DEBUG$ " : "$ ");

	/* Ensure immediate output */
	fflush(stdin);

	/* Get user input */
	*user_input = getline(&command, &command_len, stdin);

	/* Handle EOF (End of file) */
	listen_for_eof(*user_input, command, interactive, status);

	print_debug("[Info] loop_listener() -> user_input: %d", *user_input);

	if (*user_input != EOF && command[0] != '\n')
	{
		/* Delete newline character */
		command[*user_input - 1] = '\0';

		/* Execute command */
		execute_command(&command, envp, status, program_name);

		print_debug("[Info] loop_listener() -> Waiting for child process end.");
	};

	/* Handle child process exit */
	handle_exit(*status, command);
}

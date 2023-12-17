#include "simple_shell.h"

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
	int status;

	(void)argc;

	while (user_input != EOF)
	{
		if (interactive)
			printf(DEBUG ? "!$ " : "$ ");
		user_input = getline(&command, &command_size, stdin);
		if (!command)
		{
			printf("%s: getline: allocation error\n", program_name);
			break;
		};
		if (eof_listener(&user_input, interactive, command))
			break;
		command[user_input - 1] = '\0';
		if (command[0] != '\0')
		{
			create_process(command, envp, program_name, &status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
				debug_free(command, "Clearing memory (main)");
		};
	};

	return (EXIT_SUCCESS);
}

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
	/* char *program_name = argv[0]; */
	char *command = malloc(MAX_BUFFER_SIZE * sizeof(char));
	size_t command_len = MAX_BUFFER_SIZE;
	int user_input = 0;
	int i = 0;

	(void)argc;
	(void)argv;

	if (DEBUG)
		for (; envp[i]; i++)
			printf("%s\n", envp[i]);

	while (user_input != EOF)
	{
		printf("%s", DEBUG ? "DEBUG$ " : "$ ");

		user_input = getline(&command, &command_len, stdin);

		/*Supprimer le caractère de nouvelle ligne à la fin de la commande*/
		command[strcspn(command, "\n")] = '\0';
		execute_command(&command, envp);

		if (user_input == EOF)
		{
			print_debug("[Info] main() -> EOF Exiting");
			free(command);
			putchar('\n');
		};
	};

	return (0);
}

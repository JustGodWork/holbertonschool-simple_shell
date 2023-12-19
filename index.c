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
	char *program_name = argv[0];
	int user_input = 0;
	int status;

	(void)argc;

	while (user_input != EOF)
		/* Main process */
		loop_listener(&user_input, &status, envp, program_name);

	return (0);
}

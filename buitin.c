#include "simple_shell.h"

/**
 * exit_builtin - Exit shell
 * @args: Arguments
 * @status: Exit status
 * @input: Command
 * Return: 1 if success, 0 if failure
 */
int exit_builtin(char **args, int status, char *input)
{
	if (args[1])
		return (0);
	free_args(args);
	free(input);
	exit(status);
	return (1);
}

int print_env(char **args, int status, char *input)
{
	int i = 0;

	(void)status;
	(void)input;

	if (strlen(environ[i]) == 0)
		return (1);

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	free_args(args);
	return (1);
}

/**
 * is_builtin - Check if command is a builtin
 * @args: Arguments
 * @status: Exit status
 * @input: Command
 * Return: 1 if builtin, 0 if not
 */
int is_builtin(char **args, int status, char *input)
{
	int i = 0;
	builtin_t builtins[] = {
		{"exit", exit_builtin},
		{"env", print_env},
		{NULL, NULL}
	};

	if (!args)
		return (0);

	while (builtins[i].name)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return (builtins[i].handle(args, status, input));
		};
		i++;
	};
	return (0);
}

#include "simple_shell.h"

/**
 * count_command_tokens - Count valid command tokens
 * @command: Command
 * Return: Number of valid tokens
 */
int count_command_tokens(char *command)
{
	int i;
	int token_count = 0;
	int size = strlen(command);

	dinfo("Counting tokens for command: %s", command);
	for (i = 0; i < size; i++)
	{
		if (command[i] == ' ')
		{
			if (command[i + 1] != ' ' && command[i + 1] != '\n')
				token_count++;
		};
	};

	dinfo("Token count: %lu", token_count);
	return (token_count);
}

/**
 * split_args - Split command into arguments
 * @command: Command
 * Return: Array of arguments
 */
char **split_args(char *command)
{
	char *tmp;
	char *token;
	char **args;
	int size = 0;
	int token_count = count_command_tokens(command);

	args = malloc(sizeof(char *) * (token_count + 2));

	dinfo("Allocated %lu bytes for args", sizeof(char *) * (token_count + 2));

	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	};

	dinfo("Arguments array address: %p", args);

	tmp = strdup(command);
	token = strtok(tmp, " ");

	while (token)
	{
		dinfo("Token: %s", token);
		if (strcmp(token, " ") != 0 && strcmp(token, "\n"))
		{
			args[size] = strdup(token);
			size++;
		};
		token = strtok(NULL, " ");
	};
	args[size] = NULL;
	free(tmp);
	return (args);
}

/**
 * free_args - Free args
 * @args: Arguments
 * Return: void
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	};
	free(args);
}

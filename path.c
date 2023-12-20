#include "simple_shell.h"

/**
 * _getenv - Get an environment variable
 * @envp: The environment variables
 * Return: The value of the variable,
 * or NULL if not found
 */
char *getpath(char **envp)
{
	int i = 0;
	size_t key_length = strlen("PATH=");

	for (i = 0; envp[i]; i++)
		if (strncmp(envp[i], "PATH=", key_length) == 0)
			return (envp[i] + key_length);
	return (NULL);
}

/**
 * is_path - Check if a command is a path
 * @command: The command to check
 * Return: 1 if command is a path, 0 if not
 */
int is_path(char *command)
{
	int i = 0;

	while (command[i])
	{
		if (command[i] == '/')
			return (1);
		i++;
	};
	return (0);
}

/**
 * scan_dir - Scan a directory for a command
 * @command: The command to scan for
 * @envp: The environment variables
 * Return: The full path of the command,
 * or NULL if not found
*/
char *scan_dir(char *command, char **envp)
{
	char *full_path;
	char *path = getpath(envp);
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	int full_size;

	while (dir)
	{
		full_size = (strlen(dir) + strlen(command) + 2);
		full_path = malloc(sizeof(char) * full_size);
		if (!full_path)
		{
			print_debug("[Error] -> scan_dir() -> malloc() failed");
			exit(EXIT_FAILURE);
		};
		sprintf(full_path, "%s/%s", dir, command);
		print_debug(
			"[Info] -> scan_dir() -> full_path: %s",
			full_path
		);

		if (access(full_path, X_OK) == 0)
		{
			print_debug("[Success] -> scan_dir()");
			print_debug("[Info] -> scan_dir() -> Clearing memory 0");
			free(path_copy);
			return (strdup(full_path));
		};

		print_debug("[Warn] -> scan_dir() -> Searching for path...");
		dir = strtok(NULL, ":");
	};
	print_debug("[Info] -> scan_dir() -> Clearing memory -1");
	free(path_copy);
	free(full_path);
	return (NULL);
}

/**
 * get_command_path - Get the full path of a command
 * @command: The command to get the full path of
 * @envp: The environment variables
 * Return: The full path of the command,
 * or NULL if not found
 */
char *get_command_path(char *command, char **envp)
{
	char *result;

	if (is_path(command))
		return (command);

	print_debug(
		"[Info] -> get_command_path() -> command: %s",
		command
	);

	result = scan_dir(command, envp);
	if (result)
		return (result);

	print_debug("[Error] -> get_command_path() -> Exiting");

	return (NULL);
}



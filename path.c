#include "simple_shell.h"

/**
 * is_path - checks if the command is a path
 * @command: command to check
 * Return: 1 if it is a path, 0 if not
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
 * getpath - Get path from environment variables
 * Return: The value of the variable,
 * or NULL if not found
 */
char *getpath(void)
{
	int i = 0;
	size_t key_length = strlen("PATH=");

	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], "PATH=", key_length) == 0)
			return (environ[i] + key_length);
	return (NULL);
}

/**
 * scan_dir - Scan a directory for a command
 * @command: The command to scan for
 * Return: The full path of the command,
 * or NULL if not found
*/
char *scan_dir(char *command)
{
	char *full_path;
	char *path = getpath();
	char *path_copy;
	char *dir;

	if (!path)
		return (NULL);
	if (strcmp(path, "") == 0)
		return (command);
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	dinfo("scan_dir(): dir: %s, command: %s", dir, command);
	while (dir)
	{
		full_path = malloc(sizeof(char) * (strlen(dir) + strlen(command) + 2));
		dinfo("scan_dir(): full_path: allocated.");
		if (!full_path)
		{
			derror("scan_dir(): malloc() failed");
			perror("malloc failed");
			free(path_copy);
			exit(EXIT_FAILURE);
			return (NULL);
		};
		sprintf(full_path, "%s/%s", dir, command);
		dinfo("scan_dir(): full_path: %s", full_path);
		if (access(full_path, X_OK) == 0)
		{
			dsuccess("scan_dir()");
			dinfo("[Info] -> scan_dir(): Clearing memory 0");
			free(path_copy);
			return (full_path);
		};
		dwarn("scan_dir(): Searching for path...");
		dir = strtok(NULL, ":");
		free(full_path);
	};
	dinfo("scan_dir(): Clearing memory 1");
	free(path_copy);
	return (command);
}

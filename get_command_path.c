#include "simple_shell.h"

char *scan_dir(
	char *dir,
	char *command,
	char **full_path,
	int *full_size,
	char **path_copy
)
{
	while (dir)
	{
		*full_size = (strlen(dir) + strlen(command) + 2);
		*full_path = malloc(sizeof(char) * *full_size);
		if (!*full_path)
		{
			print_debug("[Error] -> scan_dir() -> malloc() failed");
			exit(EXIT_FAILURE);
		};
		sprintf(*full_path, "%s/%s", dir, command);
		print_debug(
			"[Info] -> scan_dir() -> full_path: %s",
			*full_path
		);

		if (access(*full_path, X_OK) == 0)
		{
			print_debug(
				"[Success] -> scan_dir() -> full_path: %s",
				*full_path
			);
			print_debug("[Info] -> scan_dir() -> Clearing memory 0");
			free(*path_copy);
			return (strdup(*full_path));
		};

		print_debug(
			"[Warn] -> scan_dir() -> full_path: %s",
			*full_path
		);
		dir = strtok(NULL, ":");
	};
	print_debug("[Info] -> scan_dir() -> Clearing memory -1");
	free(*path_copy);
	free(*full_path);
	return (NULL);
}

/**
 * get_command_path - Get the full path of a command
 * @command: The command to get the full path of
 * Return: The full path of the command,
 * or NULL if not found
 */
char *get_command_path(char *command)
{
	char *full_path;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	int full_size;
	char *result;

	print_debug(
		"[Info] -> get_command_path() -> command: %s",
		command
	);

	result = scan_dir(dir, command, &full_path, &full_size, &path_copy);
	if (result)
		return (result);

	print_debug("[Error] -> get_command_path() -> Exiting");

	return (NULL);
}

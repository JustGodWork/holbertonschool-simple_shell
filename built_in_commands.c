#include "simple_shell.h"

/**
 * built_in_exit - Exit the shell
 * Return: (0) always success
*/
int built_in_exit(void)
{
	print_debug("[Info] built_in_exit() -> Exiting");
	exit(EXIT_SUCCESS);
	return (0);
}

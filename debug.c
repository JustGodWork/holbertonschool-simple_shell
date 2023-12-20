#include "simple_shell.h"

/**
 * dfree - Free a pointer
 * @str: Pointer to free
 * Return: void
 */
void dfree(char *str)
{
	dwarn("freeing %p", str);
	if (str)
		free(str);
}

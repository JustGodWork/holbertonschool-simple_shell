#include "simple_shell.h"

/**
 * print_debug - Print debug
 * messages with automatic new line
 * @format: Format string
 * Return: (0) on success, (-1) on fail
 */
int print_debug(const char *format, ...)
{
	va_list args;
	int format_len = 0;

	if (DEBUG)
	{
		printf("DEBUG_PRINT: ");
		va_start(args, format);
		format_len = vprintf(format, args);
		va_end(args);
		putchar('\n');
	};
	return (format_len);
}

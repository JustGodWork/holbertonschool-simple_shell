#include "simple_shell.h"

/**
 * print_debug - Print debug messages
 * with automatic new line
 * @type: The type of debug message
 * @format: Format string
 * Return: (0) on success, (-1) on fail
 */
int print_debug(const char *type, const char *format, ...)
{
	va_list args;
	int format_len = 0;

	if (DEBUG)
	{
		printf("(DEBUG_PRINT) (%s) -> ", type);
		va_start(args, format);
		format_len = vprintf(format, args);
		va_end(args);
		putchar('\n');
	};
	return (format_len);
}

/**
 * debug_free - Print debug message and free memory
 * @buffer: The buffer to free
 * @message: The message to print
 * Return: void
*/
void debug_free(char *buffer, const char *message)
{
	print_debug(DEBUG_WARN, message ? message : "Freeing memory");
	free(buffer);
}

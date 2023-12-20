#include "simple_shell.h"

/**
 * print_debug - Print debug
 * messages with automatic new line
 * @type: Type of debug message
 * @format: Format string
 * Return: (0) on success, (-1) on fail
 */
int print_debug(char *type, const char *format, ...)
{
	va_list args;
	int format_len = 0;

	if (DEBUG)
	{
		printf("[DEBUG] %s → ", type);
		va_start(args, format);
		format_len = vprintf(format, args);
		va_end(args);
		putchar('\n');
	};
	return (format_len);
}

/**
 * dinfo - Print debug info
 * messages with automatic new line
 * @format: Format string
 * Return: Number of characters printed
*/
int dinfo(const char *format, ...)
{
	va_list args;
	int result = 0;

	va_start(args, format);
	print_debug(DINFO, format, args);
	va_end(args);

	return (result);
}

/**
 * derror - Print debug error
 * messages with automatic new line
 * @format: Format string
 * Return: Number of characters printed
*/
int derror(const char *format, ...)
{
	va_list args;
	int result = 0;

	va_start(args, format);
	print_debug(DERROR, format, args);
	va_end(args);

	return (result);
}

/**
 * dwarn - Print debug warn
 * messages with automatic new line
 * @format: Format string
 * Return: Number of characters printed
*/
int dwarn(const char *format, ...)
{
	va_list args;
	int result = 0;

	va_start(args, format);
	print_debug(DWARN, format, args);
	va_end(args);

	return (result);
}

/**
 * dsuccess - Print debug success
 * messages with automatic new line
 * @format: Format string
 * Return: Number of characters printed
*/
int dsuccess(const char *format, ...)
{
	va_list args;
	int result = 0;

	va_start(args, format);
	print_debug(DSUCCESS, format, args);
	va_end(args);

	return (result);
}

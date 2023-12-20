#include "simple_shell.h"

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

	printf("[DEBUG] [Info] → ");
	va_start(args, format);
	result = vprintf(format, args);
	va_end(args);
	putchar('\n');

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

	printf("[DEBUG] [Error] → ");
	va_start(args, format);
	result = vprintf(format, args);
	va_end(args);
	putchar('\n');

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

	printf("[DEBUG] [Warn] → ");
	va_start(args, format);
	result = vprintf(format, args);
	va_end(args);
	putchar('\n');

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

	printf("[DEBUG] [Success] → ");
	va_start(args, format);
	result = vprintf(format, args);
	va_end(args);
	putchar('\n');

	return (result);
}

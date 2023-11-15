#include "header.h"
/**
 * shell_print - prints a shell to stdout
 * @format: string to be printed
 * Return: nothing
 */
void shell_print(const char *format)
{
	write(STDOUT_FILENO, format, strlen(format));
}

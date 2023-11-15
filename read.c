#include "header.h"
/**
 * read_command - reads command from user
 * @format: buffer string
 * @n: string of string
 * Return: nothing
 */
void read_command(char *format, size_t n)
{
	format = NULL;
	n = 0;
	ssize_t read;

	read = getline(&format, &n, stdin);
	if (read != EOF)
	{
		shell_print("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		shell_print("Error reading input\n");
		exit(EXIT_FAILURE);
	}
	format[strcspn(format, "\n")] = '\0';
	free(format);
}

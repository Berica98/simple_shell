#include "header.h"
/**
 * read_command - reads command from user
 * @format: buffer string
 * @n: string of string
 * Return: nothing
 */
void read_command(char *format, size_t n)
{
	ssize_t read;

	read = getline(&format, &n, stdin);
	if (read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
		else if (read == 0)
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
	else
	{
		format[strcspn(format, "\n")] = '\0';
	}
}

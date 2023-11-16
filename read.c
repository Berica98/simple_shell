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
	char *token;
	char *args[10];

	int count = 0;

	read = getline(&format, &n, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shell_print("Error while reading input\n");
			exit(EXIT_FAILURE);
		}
	}
	format[strcspn(format, "\n")] = '\0';

	/*tokenizing the input command*/
	token = strtok(format, " ");
	while (token != NULL && count < 10 - 1)
	{
		args[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;

	execve(args[0], args, NULL);
}

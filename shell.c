#include "header.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *format = NULL;
	char *delim = " ";

	(void)argc;

	while (true)
	{
		format = get();
		if (format == NULL)
		{
			if (feof(stdin))
			{
				shell_print("\n");
				break;
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		argv = token(format, delim);
		if (argv == NULL)/* indicates an error during tokenization */
		{
			free(format);
			continue;
		}
		exec(argv);

		free(format);
		free(argv);
	}
	return (0);
}

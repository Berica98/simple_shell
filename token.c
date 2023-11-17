#include "header.h"
/**
 * token - function splits a char into tokens
 * @format: char to be splitted
 * @delim: delimeter
 *
 * Return: returns a pointer
 */
char **token(char *format, char *delim)
{
	char **argv;

	int a = 840;
	int b = 0;

	argv = malloc(sizeof(char *) * a);
	argv[b] = strtok(format, delim);
	b++;
	while (true)
	{
		argv[b] = strtok(NULL, delim);
		if (b >= a)
		{
			a += a;
			argv = _realloc(argv, a, a * (sizeof(char *)));
			if (!argv)
				exit(127);
		}
		if (argv[b] == NULL)
			break;

		b++;
	}
		return (argv);
}

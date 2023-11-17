#include "header.h"
/**
 * get - read command from user
 *
 * Return: format;
 */
char *get(void)
{
	/* declaring and initializing my variables */
	ssize_t read;

	char *format = NULL;
	size_t n = 0;
	int cal = 0;

	/* getting user input */
	read = getline(&format, &n, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			return (NULL);
		}
	}
	/* removing thr new line character*/
	cal = strlen(format);
	format[cal - 1] = '\0';
	return (format);
}

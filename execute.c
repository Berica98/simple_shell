#include "header.h"
/**
 * execute - this function executes a given command
 * @format: string to be executed
 * Return: nothing
 */
void execute(const char *format)
{
	/*int status;*/
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(format, format, (char *) NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

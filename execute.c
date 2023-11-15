#include "header.h"
/**
 * execute - this function executes a given command
 * @format: string to be executed
 * Return: nothing
 */
void execute(char *format)
{
	/*int status;*/
	pid_t pid = fork();
	char *args[] = {"ls", NULL};

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*args[0] = format;*/
		execve(format, args, NULL);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

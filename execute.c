#include "header.h"
/**
 * execute - this function executes a given command
 * @format: string to be executed
 * Return: nothing
 */
void execute(char *format)
{
	char *args[2];/*= malloc(sizeof(char *) * 2);*/

	pid_t pid = fork();
	args[0] = format;
	args[1] = NULL;
	
	if (pid == 0)
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
	/*free(format);*/
}

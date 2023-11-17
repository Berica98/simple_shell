#include "header.h"
/**
 * exec - executes a command
 * @args: this is a char arry
 *
 * Return: 0
 */
int exec(char **args)
{
	int execute;
	int status;

	pid_t my_pid = fork();

	if (my_pid == 0)
	{
		execute = execve(args[0], args, NULL);
		if (execute == -1)
		{
			perror(args[0]);
			exit(1);
		}
	}
	else if (my_pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("Error");
	}
	return (0);
}

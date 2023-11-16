#include "header.h"
/**
 * main - main shell function
 * Return: 0
 */
int main(void)
{
	pid_t pid;
	ssize_t read;
	int status;
	char *args[10];

	char *format = NULL;
	int i = 0;
	bool end = false;
	char *delim = " ";
	char *token;
	size_t size = 0;

	while (1)
	{
		shell_print("#cisfun$");
		read = getline(&format, &size, stdin);
		if (read == -1)
		{
			perror("Error :");
			exit(EXIT_FAILURE);
		}
		if (feof(stdin))
		{
			shell_print("\n");
			break;
		}
		format[strcspn(format, "\n")] = '\0';

		token = strtok(format, delim);
		while (token)
		{
			args[i++] = token;
			token = strtok(NULL, delim);
			if (!token)
			{
				end = true;
			}
		}
		if (!end)
		{
			continue;
		}
		args[i] = NULL;
		pid = fork();

		if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

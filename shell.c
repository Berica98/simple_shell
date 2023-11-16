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
	char *delim = " ";
	char *token;
	size_t size = 0;

	while (1)
	{
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
			token = (NULL, delim);
		}
		args[i] = NULL;
		pid = fork();

		if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("execv");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(&status);
			if (status != 0)
			{
				shell_print("Error executing command\n");
			}
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

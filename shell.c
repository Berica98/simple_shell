#include "header.h"
/**
 * main - main shell function
 * Return: 0
 */
int main(void)
{
	char format[20];

	while (1)
	{
		shell_print("#Cisfun$ ");
		read_command(format, sizeof(format));
		/*execute(format);*/
	}
	return (0);
}

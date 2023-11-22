#include "shell.h"

/**
 * myshell - interactive shell
 *
 * Return: no return
 */
void myshell(void)
{
	char *line;
	char **args;

	while (1)
	{
		write(1, "$ ", 2);
		line = _getline();
		args = _strtok(line);
		exec_args(args);

		free(line);
		free(args);
	}
}

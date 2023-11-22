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
	int status = -1;

	do {
		write(1, "$ ", 2);
		line = _getline();
		args = _strtok(line);
		status = exec_args(args);
		free(line);
		free(args);

		if (status >= 0)
			exit(status);
	} while (status == -1);
}

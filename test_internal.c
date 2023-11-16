#include "shell.h"

/**
 * test_builtin - Verify if the command is internal or external
 * @args: Array of pointers to arguments
 * @cmdstat: current status of the command
 * Return: 0 the command is internal or -1 if the command is external
 */

int test_builtin(char **args, int cmdstat)
{
	char *internal[2] = {
		"exit",
		"env"
	};
	int i = 0;

	while (i < 2)
	{
		if (_strcmp(args[0], internal[i]) == 0)
			break;
		i++;
	}
	if (i == 2)
		return (-1);
	if (_strcmp(internal[i], "exit") == 0)
	{
		free(args[0]);
		exit(cmdstat);
	}
	if (_strcmp(internal[i], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}
	return (0);
}

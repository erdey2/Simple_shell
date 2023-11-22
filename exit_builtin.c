#include "shell.h"

/**
 * exit_builtin - exits the shell
 * @args: list of arguments
 *
 * Return: 0 0r args[1]
 */
int exit_builtin(char **args)
{
	if (args[1])
	{
		exit(_atoi(args[1]));
	}
	else
	{
		exit(0);
	}
}

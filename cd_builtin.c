#include "shell.h"

/**
 * cd_builtin - change directory
 * @args: - array of string pointers
 *
 * Return: void
 *
 */
int cd_builtin(char **args)
{
	if (args[1] == NULL)
	{
		perror("expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in cd_builtin.c: changing dir\n");
		}
	}
	return (-1);
}

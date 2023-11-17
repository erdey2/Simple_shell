#include "shell.h"

/**
 * internal_cd - changes the current working directory
 * @args: the current directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int internal_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("cd is not successful\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in internal_cd: changing dir\n");
		}
	}
	return (-1);
}

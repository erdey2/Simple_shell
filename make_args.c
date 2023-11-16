#include "shell.h"

/**
 * make_args - put the arguments in an array
 * @cmd: the command
 * @args: Arrayof arguments
 *
 * Return: size of the array
 */

int make_args(char *cmd, char **args)
{
	int i = 0;
	char *options;
	char *aux = cmd;
	char *command;

	command = strtok(cmd, DELIM);
	args[i] = command;
	while (aux != NULL) 
	{
		++i;
		options = strtok(NULL, DELIM);
		aux = options;
	       	args[i] = options;
	}
	args[i] = NULL;
	return (i);
}

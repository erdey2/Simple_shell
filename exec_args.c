#include "shell.h"

/**
 * exec_args - check if a command is builtin or not
 * @args: - array of string pointers
 *
 * Return: array of builtins or new process
 *
 */

int exec_args(char **args)
{
	char *builtins[] = {"cd", "exit"};
	unsigned long int i = 0;

	int (*builtins_func[])(char **) = {&cd_builtin, &exit_builtin};
	if (args[0] == NULL)
		return (-1);
	for (; i < sizeof(builtins) / sizeof(char *); i++)
	{
		if (_strcmp(args[0], builtins[i]) == 0)
			return ((*builtins_func[i])(args));
	}
	return (execution(args));
}

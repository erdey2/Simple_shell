#include "shell.h"

/**
 * builtin_shell - interactive shell
 *
 * Return: no return
 */

void buitin_shell(void)
{
	char *line;
	char **args;
	int status = -1;
	do
	{
		line = get_stream();
		args = _strtok(line);
		status = exec_args(args);

		free(line);
		free(args);
		
		if (status >= 0)
			exit(status);
	} while (status == -1);
}

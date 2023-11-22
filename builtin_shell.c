#include "shell.h"

/**
 * buitin_shell - interactive shell
 *
 * Return: no return
 */

void buitin_shell(void)
{
	char *line;
	char **args;

	while (1)
	{
		line = get_stream();
		args = _strtok(line);
		exec_args(args);
	
		free(line);
		free(args);
	}
}

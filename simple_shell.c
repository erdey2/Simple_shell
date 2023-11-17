#include "shell.h"

/**
 * main - display a simple shell
 *
 * Return: - 0
 */

int main(void)
{
	char *cmd = NULL, *args[20];
	size_t cmd_len = 0;
	ssize_t bytes = 0;
	int counter = 1, test_stat = 0, cmdstats = 0, cmdstat = 0, internal_stat = 0;

	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
	bytes = getline(&cmd, &cmd_len, stdin);
	while (bytes != -1)
	{
		if (*cmd != '\n')
		{
			make_args(cmd, args);
			if (args[0] != NULL)
			{
				cmdstats = check_file(args[0]);
				if (cmdstats != 0)
				{
					test_stat = test_path(args);
					if (test_stat == 0)
						cmdstat = execution(args), free(cmd), free(*args);
					else
					{
					internal_stat = test_builtin(args, cmdstat);
					if (internal_stat != 0)
						cmdstat = cmd_not_found(args, counter), free(cmd);
					}
				}
				else
					cmdstat = execution(args), free(cmd);
			}
			else
				free(cmd);
		}
		else if (*cmd == '\n')
			free(cmd);
		cmd = NULL, counter++, write(1, "$ ", 2);
		bytes = getline(&cmd, &cmd_len, stdin);
	}
	free_buf(cmd), return (cmdstat), return (0);
}

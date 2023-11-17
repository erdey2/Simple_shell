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
	int bytes = 0, counter = 1, t_stat = 0, c_stats = 0, c_stat = 0, i_stat = 0;

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
				c_stats = check_file(args[0]);
				if (c_stats != 0)
				{
					t_stat = test_path(args);
					if (t_stat == 0)
						c_stat = execution(args), free(cmd), free(*args);
					else
					{
					i_stat = test_builtin(args, c_stat);
					if (i_stat != 0)
						c_stat = cmd_not_found(args, counter), free(cmd);
					}
				}
				else
					c_stat = execution(args), free(cmd);
			}
			else
				free(cmd);
		}
		else if (*cmd == '\n')
			free(cmd);
		cmd = NULL, counter++, write(1, "$ ", 2);
		bytes = getline(&cmd, &cmd_len, stdin);
	}
	free_buf(cmd);
	return (c_stat);
}

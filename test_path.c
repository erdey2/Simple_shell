#include "shell.h"

/**
 * test_path - test if the command can be executed
 * @args: List of arguments
 * Return: 0 if success, otherwise -1 (unsucess)
 */

int test_path(char **args)
{
	char *path = NULL;
	char *copy = NULL;
	char *dir_path = NULL;
	char *cmd_path = NULL;
	char *test_cph[121];
	int cmdstats = -1, i = 0;

	path = _getenv("PATH");
	if (path == NULL)
		return (-1);
	copy = (_strdup(path));
	dir_path = strtok(copy, ":");
	if (dir_path == NULL)
		return (-1);
	free(path);
	while (cmdstats == -1 && dir_path != NULL)
	{
		cmd_path = append_cmd(dir_path, args[0]);
		test_cph[i] = cmd_path;
		cmdstats = check_file(test_cph[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(copy);
	free_double(test_cph, i);
	if (cmdstats == 0)
	{
		args[0] = test_cph[i];
		return (0);
	}
	else
	{
		free(test_cph[i]);
		return (-1);
	}
}

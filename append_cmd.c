#include "shell.h"
/**
 * append_cmd -Append user input with PATH
 * @path: path to be appended
 * @cmd: the command 
 * Return: the address of the appended PATH
 */
char *append_cmd(char *path, char *cmd)
{
	int a, b = 0, size1, size2;
	char *cmd_path = NULL;

	if (path == NULL || cmd == NULL)
		return (NULL);

	size1 = _strlen(path);
	size2 = _strlen(cmd);
	cmd_path = malloc(size1 + size2 + 2);
	if (cmd_path == NULL)
		return (NULL);
	for (a = 0; path[a] != '\0'; a++)
	{
		cmd_path[a] = path[a];
	}
	if (path[a - 1] != '/')
	{
		cmd_path[a] = '/';
		a++;
	}
	while (cmd[b] != '\0')
	{
		cmd_path[a + b] = cmd[b];
		b++;
	}
	cmd_path[a + b] = '\0';
	return (cmd_path);
}

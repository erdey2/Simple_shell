#include "shell.h"

/**
 * builtin_env - prints environment variables
 *
 * Return: -1 on unsuccess
 */
int builtin_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}

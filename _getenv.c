#include "shell.h"

/**
 * _getenv - get the value of an environment variable
 * @env: the environment variable
 * 
 * Return: the address of the environment variable orr NULL if fails
 */
char *_getenv(char *env)
{
	int i = 0;
	const char separator[] = "=";
	char *tokens, *copied, *tok_cop;

	if (env != NULL)
	{
		if (environ == NULL)
			return (NULL);
		copied = _strdup(environ[i]);
		while (copied != NULL)
		{
			tokens = strtok(copied, separator);
			if (_strcmp(tokens, env) == 0)
			{
				tokens = strtok(NULL, separator);
				tok_cop = _strdup(tokens);
				free(copied);
				return (tok_cop);
			}
			i++;
			free(copied);
			copied = _strdup(environ[i]);
		}
	}
	return (NULL);
}

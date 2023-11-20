#include "shell.h"

/**
 * _strtok - split a line into different token
 *@line: - the user intered line to be tokenized
 *
 * Return: the address of the tokens
 */

char **_strtok(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Allocation error\n");
		exit(1);
	}
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;
		if (i >= bufsize)
			bufsize += bufsize;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			perror("reallocation error\n");
			exit(1);
		}
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

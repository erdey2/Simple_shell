#include "shell.h"

/**
 * _getline - reads entire line
 *
 * Return: the address of the read characters
 */
char *_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	size_t bytes;

	bytes = getline(&line, &bufsize, stdin);
	if (bytes < 0)
	{
		free(line);
		exit(0);
	}
	else
	{
		free(line);
		perror("error while reading\n");
		exit(1);
	}
	return (line);
}

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
	
	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
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
	}
	return (line);
}

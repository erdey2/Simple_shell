#include "shell.h"

/**
 * get_stream - get stream from stdin
 *
 * Return: address of the read stream
 *
 */
char *get_stream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = read(STDIN_FILENO, line, 1);
		if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = character;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				perror("reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}

	}
}

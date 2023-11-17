#include "shell.h"

/**
 * free_buf - Free the allocated memory
 *
 * @line: Input entered by user
 */
void free_buf(char *line)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		_putchar('\n');
		free(line);
	}
	if (!isatty(STDIN_FILENO))
		free(line);
}

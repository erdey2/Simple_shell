#include "shell.h"

/**
 * readline - custum readline
 * @s: the string
 * @size: buffer size
 *
 * Return: the total bytes read
 */

int readline(char s[], int size)
{
	char *tmp = s;

	while (--size > 0 && read(0, tmp, 1) != 0 && *tmp++ != '\n');
	*tmp = '\0';
	return (tmp - s);
}


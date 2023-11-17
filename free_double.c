#include "shell.h"

/**
 * free_double - free allocated memory
 * @doublea: pointer to double array
 * @heigth: Heigth of the array
 */

void free_double(char **doublea, int heigth)
{
	int i = 0;

	if (doublea == NULL)
	{
		return;
	}

	while (i < heigth)
	{
		free(doublea[i]);
		i++;
	}
}

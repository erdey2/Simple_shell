#include "shell.h"

/**
 * _strcmp - compare two strings
 * @s1: the first string
 * @s2: the 2nd string
 *
 * Return: 0 if they are equal, - if s1 greater than s2, otherwise +
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0, result;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;
	result = (*(s1 + i) - *(s2 + i));
	
	return (result);
}

/**
 * _strlen - determine the length of a string
 * @s1: the string which we want its length to be determined
 *
 * Return: the size
 */
int _strlen(const char *s1)
{
	int i = 0;

	while (*s1)
	{
		i++;
	}
	return (i);
}

/**
* _strncmp - compares two strings up to n bytes
* @s1: compared to s2
* @s2: compared to s1
* @n: number of bytes
*
* Return: difference between s1 and s2
*/

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

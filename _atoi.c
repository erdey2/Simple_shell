#include "shell.h"

/**
 * _atoi - convert a string to int
 * @s: the string address to be converted
 * Return: an integer
 */
int _atoi(char *s)
{
	int counter = 0, minimum = 1, isinteger = 0;
	unsigned int ni = 0;

	while (s[counter])
	{
		if (s[counter] == '-')
		{
			minimum *= -1;
		}
		while (s[counter] >= '0' && s[counter] <= '9')
		{
			isinteger = 1;
			ni = (ni * 10) + (s[counter] - '0');
			counter++;
		}
		if (isinteger == 1)
		{
			break;
		}
		counter++;
	}
	ni *= minimum;
	return (ni);
}

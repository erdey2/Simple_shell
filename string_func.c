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

	while (s1[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - print a character to the stdout
 * @c: The character to be printed
 *
 * Return: On success 1 otherwise -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strdup - copy a string
 * @s1: the string to be copied
 *
 * Return: the copied string
 */
char *_strdup(char *s1)
{
	unsigned int i, size;
	char *duplicate;

	if (s1 == NULL)
		return (NULL);
	for (size = 0; s1[size] != '\0'; size++)
		;
	duplicate = malloc(sizeof(char) * (size + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= size; i++)
		duplicate[i] = s1[i];
	return (duplicate);
}

/**
 * *_strcpy - copy a given string
 * @s1: destination string
 * @s2: source string
 * Return: char
 */
char *_strcpy(char *s1, char *s2)
{
	int len = 0, counter = 0;

	while (*(s2 + len) != '\0')
	{
		len++;
	}
	for (; counter < len; counter++)
	{
		s1[counter] = s2[counter];
		s1[len] = '\0';
	}
	return (s1);
}

#include "shell.h"

/**
 * check_match - checks of a given character matches any character
 * @c: the character to be checked
 * @s1: the delimiter
 * Return: 1 if there is match, 0 otherwise
 */
unsigned int check_match(char c, const char *s1)
{
	unsigned int i = 0;
	
	while (s1[i] != '\0')
	{
		if (c == s1[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtok - split a given string into tokens
 * @s1: the string to be splited
 * @s2: the string to be used as a spliter
 * 
 * Return: pointer to the next token or NULL
 */
char *mystrtok(char *s1, const char *s2)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

	if (s1 != NULL)
		new_token = s1;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (check_match(tokens[i], s2) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tokens = new_token + i;
	new_token = tokens;
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (check_match(new_token[i], s2) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}

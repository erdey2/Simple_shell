
/**
 * _strcat - put a given string at the end of another string
 * @s1: the destination
 * @s2: the source
 *
 * Return: an address of the concatenated string
 */
char *_strcat(char *s1, char *s2)
{
	char *p = s1;

	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = *s2;
	return (p);
}

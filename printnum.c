#include "shell.h"

/**
 * print_nums - print error message
 * @n: number to be printed
 *
 * Return: Number
 */

int print_nums(int n)
{
	unsigned int number;
	int i = 0;

	if (n < 0)
	{
		number = -n;
		i = i + _putchar('-');
	}
	else
	{
		number = n;
	}
	if (number / 10 != '\0')
		i = i + print_nums(number / 10);
	i = i + _putchar(number % 10 + '0');
	return (i);
}

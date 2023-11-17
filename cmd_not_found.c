#include "shell.h"

/**
 * cmd_not_found - prints error message when a command is not found
 * @args: user input array of pointers to strings
 * @counter: holds how many times the shell executed
 *
 * Return: command not found
 */
int cmd_not_found(char *args[], int counter)
{
	char *relative_name = "hsh";
	char *absolute_name = "./hsh";

	if (isatty(STDIN_FILENO) == 1)
		write(2, relative_name, 3);
	else
	{
		write(2, absolute_name, 5);
	}
	write(2, ": ", 2);
	print_nums(counter);
	write(2, ": ", 2);
	write(2, args[0], _strlen(args[0]));
	write(2, ": not found\n", 12);
	return (127);
}

#include "shell.h"

/**
 * main - the entry point
 * 
 * Return: 0 (always success)
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		/* shell running in interactive way */
		myshell();
	}
	else
	{
		/* shell running in non-interactive */
		buitin_shell();
	}
	return (0);
}

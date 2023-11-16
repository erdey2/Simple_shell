#include "shell.h"

/**
 * execution - create a new process & replace 
 * the parent process image with the child
 * @args: Array of arguments from a user
 * Return: 0 on success
 */
int execution(char **args)
{
	pid_t childpid = 0;
	int status = 0;

	childpid = fork();
	if (childpid < 0)
		write(1, "failed\n", 7);
	else if (childpid > 0)
	{
		waitpid(-1, &status, 0);
	}
	else
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("hsh");
			exit(-1);
		}
		exit(0);
	}
	return (0);
}

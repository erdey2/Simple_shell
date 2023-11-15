#include "shell.h"

/**
 * main - display a simple shell
 * @argc - number of arguments
 * @argv - array of pointers to arguments  
 * 
 * Return - 0
 */

extern char **environ;

int main(void)
{
	char *args[] = {NULL, NULL};
	char *cmd = NULL;
	size_t cmd_len = 0;
	ssize_t bytes;

	pid_t childpid;
	int status;

	while (1)
	{
		write(1, "cisfun$ ", 9);
		bytes = getline(&cmd, &cmd_len, stdin);
		cmd[bytes - 1] = '\0';
		args[0] = cmd;

		childpid = fork();
		if (childpid < 0)
		{
			perror(args[0]);
			exit(1);
		}
		else if (childpid > 0)
		{
			wait(&status);
		}
		else
		{
			execve(*args, args, environ);
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", args[0]);
			exit(1);
		}
	}
	return (0);
}


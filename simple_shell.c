#include "shell.h"

/**
 * main - display a simple shell
 * @argc - number of arguments
 * @argv - array of pointers to arguments  
 * 
 * Return - 0
 */

extern char **environ;

int main(int argc, char *argv[])
{
	char *args[] = {NULL, NULL};
	char *cmd = NULL;
	ssize_t n_bytes = 0;
	size_t bytes = 0;

	size_t childpid;
	int status;

	while (1)
	{
		write(1, "cisfun$ ", 9);
		bytes = getline(&cmd, &n_bytes, stdin);
		cmd[n_bytes - 1] = '\0';
		args[0] = cmd;

		childpid = fork();
		if (childpid == -1)
		{
			perror(argv[0]);
			exit(1);
		}
		else if (childpid > 0)
		{
			wait(&status);
		}
		else
		{
			execve(argv[0], args, environ);
			exit(100);
		}

	
	}
}


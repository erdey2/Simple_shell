#include "shell.h"

/**
 * execution - create a new process & replace the parent image with new program
 * @args: array of string pointers
 * 
 * Return: 0 (success always)
 */
int execution(char **args)
{
	pid_t childpid;
	int status;
	char cmd[64];
	
	_strcpy(cmd, "/bin/");
	_strcat(cmd, args[0]);

	childpid = fork();
	if (childpid < 0)
	{
		perror("fork failed\n");
		exit(1);
	}
	else if (childpid == 0)
	{
		if (*args[0] == '/')
		{
			if (execve(*args, args, environ) == -1)
			{
				perror("execve failed\n");
				exit(1);
			}
		}
		else
		{
			if (execve(cmd, args, environ) == -1)
			{
				perror("execve failed\n");
			       	exit(1);
			}
		}
		exit(0);
	}
	else
	{
		childpid = wait(&status);
		if (childpid == -1)
		{
			perror("wait error\n");
			exit(2);
		}
	}
	return (-1);
}

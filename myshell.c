#include "shell.h"
/**
 * main - the entry point
 *
 *Return: - 0 (success always)
 *
 *
 */
int main(void)
{
	pid_t childpid;
	int status;
	char cmd[64], *line, **args;

	while (1)
	{
		write(1, "$ ", 2);
		line = _getline();
		args = _strtok(line);
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
					perror("execve failed\n"), exit(1);
				}
			}
			exit(0);
		}
		else
			wait(&status);
	}
	return (0);
}

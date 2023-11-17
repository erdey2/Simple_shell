#include "shell.h"

/**
 * main - display a simple shell
 * @argc: - number of arguments
 * @argv: - array of pointers to arguments
 *
 * Return: - 0
 */

int main(int argc, char *argv[])
{
	char *args[] = {NULL, NULL};
	char *cmd = NULL;
	size_t cmd_len = 0;
	ssize_t bytes;
	pid_t childpid;
	int status = 0, exec_status = 0;

	(void)argc;
	while (1)
	{
		write(1, "$ ", 2);
		bytes = getline(&cmd, &cmd_len, stdin);
		cmd[bytes - 1] = '\0';
		if (_strcmp(cmd, "exit") == 0)
			exit(0);
		if (_strcmp(cmd, "env") == 0)
			return (builtin_env());
		args[0] = cmd;
		childpid = fork();
		if (childpid < 0)
		{
			perror(argv[0]);
			exit(1);
		}
		else if (childpid == 0)
		{
			exec_status = execve(*args, args, environ);
			if (exec_status == -1)
			{
				exec_status = 126; /* permission denied or unable to execute */
				perror("hsh");
				exit(exec_status);
			}
			exit(0);
		}
		else
			wait(&status);
		exec_status = WEXITSTATUS(status);
	}
	return (0);
}

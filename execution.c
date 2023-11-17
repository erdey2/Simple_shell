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
	int status = 0, exec_status = 0;

	childpid = fork();
	if (childpid < 0)
		perror("error in new_process: forking ");
	else if (childpid == 0)
	{
		exec_status = execve(args[0], args, environ);
		if (exec_status == -1)
		{
			exec_status = 126; /* permission denied or unable to execute */
			perror("hsh");
			exit(exec_status);
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
	exec_status = WEXITSTATUS(status);
	return (exec_status);
}

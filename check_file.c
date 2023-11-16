#include "shell.h"

/**
 * check_file - check if a file exist
 * @path: the path of the file
 *
 * Return: 0 if the file is found -1 if not found
 */
int check_file(char *path)
{
	int fd;
	
	fd = (open(path, O_RDONLY));
	if (fd != -1)
	{
		close(fd);
		return (0);
	}
	else
		return (-1);

}

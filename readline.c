#include "shell.h"

/**
 * readline - custum readline
 * @fd: the file pointer
 * @buf: the container for the read
 * @nbytes: the size of the number of read
 *
 * Return: the total bytes read
 */

int readline(int fd, char *buf, int nbytes)
{
	int numread = 0, val;

	while (numread < nbytes - 1)
	{
		val = read(fd, buf + numread, 1);
		if ((val == -1) && (errno == EINTR))
			continue;
		if ((val == 0) && (numread == 0))
			return (0);
		if (val == 0)
			break;
		if (val == -1)
			return (-1);
		numread++;
		if (buf[numread - 1] == '\n')
		{
			buf[numread] = '\0';
			return (numread);
		}
	}
	errno = EINVAL;
	return (-1);
}

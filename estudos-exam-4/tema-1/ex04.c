#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int		fds[2];
	int		status;
	int		len = 100;
	char	buf[len];
	ssize_t	size;

	pipe(fds);
	write(fds[1], "Hello world", 12);
	close(fds[1]);
	
	size = read(fds[0], buf, len);
	buf[size] = '\0';
	close(fds[0]);

	printf("fd[0]: %s\n", buf);
	return (0);
}
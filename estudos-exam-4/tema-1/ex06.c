#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	printf("Only a test 1.\n");
	printf("Only a test 2.\n");
	close(fd);
	return (0);
}
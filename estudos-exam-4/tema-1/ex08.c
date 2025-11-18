#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_open(void)
{
	int p_fd[2];

	if (pipe(p_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}

	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		execvp("ls", (char *const[]) {"ls", "-la", NULL});
		exit(0);
	}
	close(p_fd[1]);
	return (p_fd[0]);
}

int main(void)
{
	int fd;
	int len = 1024;
	char buf[len];
	ssize_t size;

	fd = ft_open();
	if (fd == -1)
	{
		perror("ft_open");
		return (1);
	}
	size = read(fd, buf, len);
	buf[size] = '\0';
	close(fd);
	printf("%s", buf);
	return (0);
}
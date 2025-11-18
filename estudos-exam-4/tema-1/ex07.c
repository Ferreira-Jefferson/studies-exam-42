#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fds[2];
	int len = 1024;
	char buf[len];
	ssize_t size;

	if (pipe(fds))
	{
		perror("pipe");
		return (1);
	}

	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		execvp("ls", (char *const[]){"ls", "-la", NULL});
		exit(0);
	}
	else
	{
		close(fds[1]);
		size = read(fds[0], buf, len);
		buf[size] = '\0';
		close(fds[0]);
		printf("%s", buf);
	}
	return (0);
}
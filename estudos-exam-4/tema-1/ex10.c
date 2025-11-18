#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_open(char type)
{
	int fds[2];

	if (type != 'w' && type != 'r')
		return (-1);
	if (pipe(fds) == -1)
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
		if (type == 'r')
		{
			close(fds[0]);
			dup2(fds[1], STDOUT_FILENO);
			close(fds[1]);
			if (execvp("ls", (char *const[]){"ls", "-la", NULL}))
			{
				perror("execvp");
				exit(-1);
			}
			exit(0);
		}
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		if (execvp("grep", (char *const[]) {"grep", "shell", NULL}))
		{
			perror("execvp");
			exit(0);
		}
		exit(0);
	}
	if (type == 'w')
	{
		close(fds[0]);
		return (fds[1]);
	}
	close(fds[1]);
	return (fds[0]);
}

int main(int argc, char *argv[])
{
	int len = 1024;
	char buf[len];
	ssize_t size;

	if (argc == 1)
		return (0);

	if (argv[1][0] == 'r')
	{
		int r = ft_open('r');
		if (r == -1)
		{
			perror("ft_open");
			return (1);
		}
		size = read(r, buf, len);
		buf[size] = '\0';
		printf("%s", buf);
		close(r);
	}
	if (argv[1][0] == 'w')
	{
		int w = ft_open('w');
		if (w == -1)
		{
			perror("ft_open");
			return (1);
		}
		write(w, "teste\n", 6);
		write(w, "teste shell\n", 12);
		write(w, "picoshell teste\n", 16);
		write(w, "teste Shell\n", 12);
		close(w);
	}
	return (0);
}

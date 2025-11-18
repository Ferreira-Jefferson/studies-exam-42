#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int ft_open(void)
{
	int p_fd[2];

	if (pipe(p_fd))
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
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		execvp("grep", (char *const[]) {"grep", "picoshell", NULL});
		perror("execvp");
		exit(1);
	}
	close(p_fd[0]);
	return (p_fd[1]);
}

int main(int argc, char *argv[])
{
    int fd = ft_open();
    if (fd == -1) {
        perror("ft_open");
        return (1);
    }

    write(fd, "picoshell\n", 10);
    write(fd, "outracoisa\n", 11);
    write(fd, "um picoshell\n", 13);
    write(fd, "shell teste\n", 12);
    write(fd, "picoShell\n", 10);
    write(fd, "picoshell teste\n", 16);
    close(fd);

    int status;
    wait(&status);
}
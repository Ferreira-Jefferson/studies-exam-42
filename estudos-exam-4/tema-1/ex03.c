#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid = fork();

	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("In children\n");
		execvp("ls", (char *const[]) {"ls", "-la", NULL});
		exit (0);
	}
	printf("Should show father message.\n");
	return (0);
}
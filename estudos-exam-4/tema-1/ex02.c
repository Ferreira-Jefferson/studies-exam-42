#include <stdio.h>
#include <unistd.h>

int main()
{
	execvp("ls", (char *const[]) {"ls", "-la", NULL});
	printf("Don't show\n");
}
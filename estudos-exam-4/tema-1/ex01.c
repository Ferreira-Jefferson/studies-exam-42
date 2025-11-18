#include <unistd.h>
#include <stdio.h>

int main()
{
	double	money;
	int		pid;

	money = 10.5;
	pid = fork();

	if (pid == 0)
	{
		money = 3.50;
		printf("I'm children, I have $ %.2f\n", money);
	}
	else 
	{
		printf("I'm father, I have $ %.2f\n", money);
	}
	return (0);
}
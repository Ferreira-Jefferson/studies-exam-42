#include <stdio.h>

#define N 3

char *letras = "ABC";
char atual[N + 1];
int usadas[N] = {0};

void permuta(int index)
{
	if (index == N)
	{
		atual[index] = '\0';
		printf("%s\n", atual);
		return ;
	}

	int i = 0;
	while (i < N)
	{
		if (!usadas[i])
		{
			usadas[i] = 1;
			atual[index] = letras[i];
			permuta(index + 1);
			usadas[i] = 0;
		}
		i++;
	}
}

int main()
{
	permuta(0);
	return (0);
}
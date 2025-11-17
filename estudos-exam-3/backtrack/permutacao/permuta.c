#include <stdio.h>
#include <string.h>

#define N 3

char *letras = "ABC";
int usadas[N];
char atual[N + 1];

void permuta(int index)
{
	int i;
	if (index == N)
	{
		atual[N] = '\0';
		printf("%s\n", atual);
		return ;
	}

	i = 0;
	while (i < N)
	{
		if (usadas[i] == -1)
		{
			usadas[i] = index;
			atual[index] = letras[i];
			permuta(index + 1);
			usadas[i] = -1;
		}
		i++;
	}
}

int main()
{
	memset(usadas, -1, sizeof(usadas));
	permuta(0);
	return (0);
}

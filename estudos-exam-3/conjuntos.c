#include <stdio.h>

#define N 3

int conjunto[N] = {1, 2, 3};
int subconjunto[N];

void print(int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		printf("%d ", subconjunto[i]);
		i++;
	}
}
void back(int i, int len)
{
	if (i == N)
	{
		printf("[");
		print(len);
		printf("]\n");
		return ;
	}
	back(i+1, len);

	subconjunto[len] = conjunto[i];
	back(i+1, len+1);
}

int main()
{
	back(0, 0);
}
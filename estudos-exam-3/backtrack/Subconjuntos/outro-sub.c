#include <stdio.h>

#define N 3
int conjunto[N] = {1,2,3};
int sub[N];

void subconjunto(int i, int len)
{
	if (i == N)
	{
		printf("{");
		for (int j = 0; j < len; j++)
		{
			printf("%d", sub[j]);
			if (j < len - 1)
				printf(", ");
		}
		printf("}\n");
		return ;
	}
	subconjunto(i+1, len);
	
	sub[len] = conjunto[i];
	subconjunto(i+1, len+1);
}
int main()
{
	subconjunto(0,0);
	return 0;
}
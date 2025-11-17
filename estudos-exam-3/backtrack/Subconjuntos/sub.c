#include <stdio.h>

#define N 3

int conjunto[] = {1, 2, 3};
int sub[N];

void subconjuntos(int i, int quant_sub)
{
	if (i == N)
	{
		printf("{");
		for (int j = 0; j < quant_sub; j++)
		{
			printf("%d", sub[j]);
			if (j < quant_sub - 1)
				printf(", ");
		}
		printf("}\n");
		return ;
	}

	subconjuntos(i+1, quant_sub);
	
	sub[quant_sub] = conjunto[i];
	subconjuntos(i+1, quant_sub+1);

}

int main(){

	subconjuntos(0, 0);
	return (0);
}
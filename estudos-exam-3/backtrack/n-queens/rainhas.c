#include <stdio.h>

#define N 12
int tabuleiro[N][N] = {0};
int i = 0;

void print_tabuleiro()
{	printf("### %d ###", i++);
	for (int l = 0; l < N; l++)
	{
		for (int c = 0; c < N; c++)
			printf(tabuleiro[l][c] ? "Q " : ". ");
		printf("\n");
	}
}

int seguro(int lin, int col)
{
	for (int x=0; x < lin; x++)
		if (tabuleiro[x][col]) return 0;

	for (int l=lin-1, c=col-1; l >=0 && c >= 0; l--, c--)
		if (tabuleiro[l][c]) return 0;

	 for (int i=lin-1, j=col+1; i>=0 && j<N; i--, j++)
        if (tabuleiro[i][j]) return 0;
	
	 for (int i=lin-1, j=col-1; i>=0 && j<N; i--, j--)
        if (tabuleiro[i][j]) return 0;

	return 1;
}

void rainhas(int linha)
{
	if (linha == N)
	{
		print_tabuleiro();
		printf("\n");
		return ;
	}
	for (int col = 0; col < N; col++)
	{
		if (seguro(linha, col))
		{
			tabuleiro[linha][col] = 1;
			rainhas(linha + 1);
			tabuleiro[linha][col] = 0;
		}
	}
}
int main(){
	rainhas(0);
}

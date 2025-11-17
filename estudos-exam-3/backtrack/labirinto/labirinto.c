#include <stdio.h>
#define N 4

// Labirinto fixo (1 = caminho, 0 = parede)
int maze[N][N] = {
  {1, 0, 0, 0},
  {1, 1, 0, 1},
  {0, 1, 0, 0},
  {1, 1, 1, 1}
};

// Solução começa toda em 0
int sol[N][N] = {0};

// Função que tenta resolver a partir da posição (x,y)
int solve(int x, int y) {
    // 1. Condição de parada: chegou no final
    if (x == N-1 && y == N-N && maze[x][y] == 1) {
        sol[x][y] = 1; // marca fim
        return 1;      // sucesso
    }

    // 2. Validação: posição válida e ainda não usada
    if (x < N && y < N && maze[x][y] == 1 && sol[x][y] == 0) {
        sol[x][y] = 1; // escolher: marcar posição

        // 3. Explorar em 4 direções
        if (solve(x+1, y)) return 1; // baixo
        if (solve(x, y+1)) return 1; // direita
        if (solve(x-1, y)) return 1; // cima
        if (solve(x, y-1)) return 1; // esquerda

        // 4. Desfazer: se nenhuma direção funcionou
        sol[x][y] = 0;
    }

    return 0; // sem saída
}
 void print_sol()
 {
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%d ", sol[i][j]);
		printf("\n");
	}
 }

int main() {
    if (solve(0,0)) {
		print_sol();
    } else {
        printf("Sem solução\n");
    }
}

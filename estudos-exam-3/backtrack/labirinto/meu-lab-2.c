#include <stdio.h>

#define N 4

int maze[N][N] = {
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{0, 1, 1, 1},
	{1, 1, 0, 1}
};

int sol[N][N] = {0};

void print(int matriz[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			printf("%d ", matriz[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int solve(int x, int y)
{
	if (x == N - 1 && y == 0 && maze[x][y] == 1 && sol[x][y] == 0)
	{
		sol[x][y] = 1;
		return 1;
	}

	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0)
	{
		sol[x][y] = 1;

		if (solve(x, y+1)) return 1;
		if (solve(x+1, y)) return 1;
		if (solve(x-1, y)) return 1;
		if (solve(x, y-1)) return 1;

		sol[x][y] = 0;
	}
	return 0;
}

int main()
{
	print(maze);
	print(sol);
	solve(0,0);
	print(sol);
	return 0;
}
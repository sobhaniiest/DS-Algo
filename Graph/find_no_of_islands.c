#include <stdio.h>

int isSafe(int r, int c, int x, int y)
{
	if ((x >= 0 && x < r) && (y >= 0 && y < c))
		return 1;
	else
		return 0;
}


void DFS(int r, int c, int x, int y, int M[][c], int V[][c])
{
	int rownbr[9] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int colnbr[9] = {-1, 0, 1, -1, 1, -1, 0, 1};

	V[x][y] = 1;

	for (int i = 0; i < 8; i++)
	{
		if (isSafe(r, c, x+rownbr[i], y+colnbr[i]) == 1 && V[x+rownbr[i]][y+colnbr[i]] == 0 && M[x+rownbr[i]][y+colnbr[i]] == 1)
			DFS (r, c, x+rownbr[i], y+colnbr[i], M, V);
	}
}


int countIslands(int r, int c, int M[][c])
{
	int visited[r][c];
	int i, j, count = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			visited[i][j] = 0;
	}

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (visited[i][j] == 0 && M[i][j] == 1)
			{

				DFS(r, c, i, j, M, visited);
				count++;
			}
		}
	} 
	return count;
}


int main() 
{ 
    int M[3][5] = { { 1, 1, 0, 0, 0 }, 
                    { 0, 1, 0, 0, 1 }, 
                    { 1, 0, 0, 1, 1 },}; 
  
    printf("Number of islands is: %d\n", countIslands(3, 5, M)); 
  
    return 0; 
}

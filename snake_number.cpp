#include <stdio.h>
#include <string.h>
#define maxn 4

int sqr[maxn][maxn];

int main()
{
	int n;
	scanf("%d", &n);
	int count = 1;
	int row = 0, col = n - 1;
	memset(sqr, 0, sizeof(sqr));
	sqr[row][col] = 1;
	
	while(count < n*n)
	{
		while(row < n - 1 && !sqr[row + 1][col]) sqr[++row][col] = ++count;
		while(col > 0 && !sqr[row][col - 1]) sqr[row][--col] = ++count;
		while(row > 0 && !sqr[row - 1][col])  sqr[--row][col] = ++count;
		while(col < n - 1 && !sqr[row][col + 1]) 
			sqr[row][++col] = ++count;
	}
	
	for(row = 0; row < n; row++)
	{
		for(col = 0; col < n; col++)
		{
			printf("%3d", sqr[row][col]);
		}
		printf("\n");
	}
		
	
}

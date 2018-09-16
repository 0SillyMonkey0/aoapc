#include <stdio.h>
#include <string.h>

#define maxm 55
#define maxn 1005

char DNA[] = {'A', 'C', 'G', 'T'};
int find_max(char dna[maxm][maxn], int m, int col)
{
	int count[4] = {0};
	for(int i = 0; i < m; i++)
		for(int j = 0; j < 4; j++)
			if(dna[i][col] == DNA[j])
				count[j]++;
	int max_ind = 0;
	for(int i = 0; i < 4; i++)
		if(count[i] > count[max_ind])
			max_ind = i;
	return max_ind;			
}


int distance(char dna[maxm][maxn], int m, int col, int ind)
{
	int dis = 0;
	for(int i = 0; i < m; i++)
		if(dna[i][col] != DNA[ind])
			dis++;
			
	return dis;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		char dna[maxm][maxn] = {0};
		for(int i = 0; i < m; i++)
			scanf("%s", dna[i]);
			
		char best_seq[maxn] = {0};
		int dis = 0;
		for(int i = 0; i < n; i++)
		{
			int ind = find_max(dna, m, i);
			best_seq[i] = DNA[ind];
			dis += distance(dna, m, i, ind);
		}
		printf("%s\n%d\n", best_seq, dis);
	}
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 99999999;

int n, m, st, en;
int w[510][510], d[510], num[510], v[510] = {0}, resnum[510], maxnum[510];

int  main()
{
	cin >> n >> m >> st >> en;
	for(int i = 0; i < n; i++)
		cin >> resnum[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			w[i][j] = INF;
	for(int i = 0; i < n; i++)
		d[i] = (i == st ? 0 : INF);
	for(int i = 0; i < m; i++)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		w[v][u] = w[u][v] = weight;
	}	
		maxnum[st] = resnum[st];
	num[st] = 1;

	// Dijkstra
	for(int i = 0; i < n; i++) 
	{
		int x, m = INF;
		for(int y = 0; y < n; y++)
			if(!v[y] && d[y] < m) m = d[x = y];
		v[x] = 1;
		for(int y = 0; y < n; y++)
		{	if(!v[y] && w[x][y] != INF)
			{
				if(d[x] + w[x][y] < d[y])
				{
					d[y] = d[x] + w[x][y];
					num[y] = num[x];
					maxnum[y] = maxnum[x] + resnum[y];
				}	
				else if(d[x] + w[x][y] == d[y] )
				{
					num[y] = num[y] + num[x];
					if(maxnum[x] + resnum[y] > maxnum[y])
						maxnum[y] = maxnum[x] + resnum[y];
				}
			}	
		}
	}
	cout << num[en] <<" "<< maxnum[en] << endl;

}

	
	

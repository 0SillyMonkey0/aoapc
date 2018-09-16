#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 100 + 5;
int G[maxn][maxn];
int c[maxn], topo[maxn], t;
int m, n;

bool dfs(int u)
{
	c[u] = -1;
	for(int v = 0; v < n; v++)
	{
		if(G[u][v])
		{
			if(c[v] < 0) return false;
			if(!c[v]) dfs(v);
		}
	}
	c[u] = 1;
	topo[--t] = u;
	return true;
}

bool toposort()
{
	t = n;
	memset(c, 0, sizeof(c));
	for(int u = 0; u < n; u++)
		if(!c[u])	
			if(!dfs(u))  return false;
	return true;
}

int main()
{
	while(cin >> n >> m, n)
	{
		memset(G, 0, sizeof(G));
		for(int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u - 1][v - 1] = 1;
		}
		if(toposort())
		{
			for(int i = 0; i < n - 1; i++)
				cout << topo[i] + 1 << " ";
			cout << topo[n - 1] + 1 << endl;
		}	
	}
	return 0;
}





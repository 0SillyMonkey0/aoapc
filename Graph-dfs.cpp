#include<cstdio>
#include<cstring>
#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

const int maxn = 10;
vector<int>  G[maxn];
int color[maxn], p[maxn];

void build_graph()
{
	int n;
	cin >> n;
	for(int i = 0;i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
} 

void dfsVisit(int node)
{
	color[node] = 1;
	for(int i = 0; i < G[node].size(); i++)
	{
		if(color[i] == 0)
		{
			cout << i << endl;
			p[i] = node;
			dfsVisit(i);
		}
		else if(color[i] == 1 && p[node] != i)
		{
			cout << "cycle\n";
		}
	}
	color[node] = 2;
}

void dfs()
{
	memset(color, 0, sizeof(color));
	memset(p, -1, sizeof(p));
	for(int i = 0; i < maxn; i++)
	{
		if(!G[i].empty())
		{
			if(color[i] == 0)
			{
				cout << i << endl;
				dfsVisit(i);
			}	
		}
	}
} 
 
int main()
{
	build_graph();
	dfs();
	return 0;
}
 
 
 
 
  

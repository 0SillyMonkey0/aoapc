#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int vis[100] = {0}, r[10], p[10];
struct edge{
	int u, v, weight;
} edges[10];

int cmp(int i, int j)
{
	return edges[i].weight < edges[j].weight;
}

int find(int i)
{
	if(p[i] == i)
		return p[i];
	else
		return find(p[i]);
}
int kruskal()
{
	for(int i = 0; i < 10; i++)
		r[i] = p[i] = i;
	sort(r, r + 10, cmp);
	int ans = 0;
	for(int i = 0; i < 10; i++)
	{
		int u = edges[r[i]].u, v = edges[r[i]].v, w = edges[r[i]].weight;
		int x = find(u),y = find(v);
		if(x !=  y)
		{
			p[x] = y;
			ans += w;
		}	
	}
	return ans;
} 
    
int  main()
{
	for(int i = 0; i < 10; i++)
	{
		cin >> edges[i].u >> edges[i].v >> edges[i].weight;	
	}	
	cout << kruskal(); 
}

	
	

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;


const int maxn = 100000 + 5;
const int INF = 1 << 30;

struct Edge{
	int u, v, c;
	Edge(int u = 0, int v = 0, int c = 0):u(u), v(v), c(c){	}
};
vector<Edge> G[maxn];
void AddEdge(int u, int v, int c)
{
	G[u].push_back(Edge(u, v, c));	
}
int d[maxn], vis[maxn];
int n, m;

void rev_bfs()
{
	memset(vis, 0, sizeof(vis));
	d[n - 1] = 0;
	vis[n - 1] = 1;
	
	queue<int> q;
	int u = n - 1;
	q.push(u);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v;
			if(!vis[v])
			{
				d[v] = d[u] + 1;
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	
	vector<int > next, ans;
	next.push_back(0);
	for(int i = 0; i < d[0]; i++)
	{
		int min_color = INF;
		for(int j = 0; j < next.size(); j++)
		{
			int u = next[j];
			for(int k = 0; k < G[u].size(); k++)
			{
				int v = G[u][k].v;
				if(d[u] == d[v] + 1)
				{
					if(G[u][k].c < min_color)
					min_color = G[u][k].c; 
				}
			}
		}
		
		ans.push_back(min_color);
		vector<int> next2;
		
		for(int j = 0; j < next.size(); j++)
		{
			int u = next[j];
			for(int k = 0; k < G[u].size(); k++)
			{
				int v = G[u][k].v;
				if(d[u] == d[v] + 1 && !vis[v] && G[u][k].c == min_color)
				{
					vis[v] = true;
					next2.push_back(v);
				}
			}
		}
		next = next2;
	}
	printf("%d\n", ans.size());
	printf("%d", ans[0]);
	for(int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
	printf("\n");
}



int main()
{
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; i++) G[i].clear();
		while(m--)
		{
			int u, v, c;
			cin >> u >> v >> c;
			AddEdge(u - 1, v - 1, c);
			AddEdge(v - 1, u - 1, c);
		}		
		rev_bfs();
		bfs();
	}
	return 0;
}

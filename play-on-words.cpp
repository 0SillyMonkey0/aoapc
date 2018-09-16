#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 26;
int G[maxn][maxn];
int degree[maxn];
int showed[maxn], visited[maxn];

void dfs(int u)
{
	visited[u] = 1;
	for(int v = 0; v < maxn; v++)
	{
		if(G[u][v] && !visited[v] && v != u)
		{
			dfs(v);
		}		
	}
}

bool is_connect(int u)
{
	dfs(u);
//	for(int i = 0; i < maxn; i++)
//		cout << visited[i] << " ";
//	cout << endl;
//	
//	for(int i = 0; i < maxn; i++)
//		cout << showed[i] << " ";
//	cout << endl;
	
	for(int i = 0; i < maxn; i++)
		if(showed[i] != visited[i])
			return false;
	return true;
}


bool degree_fit()
{
	vector<int> d;
	for(int i = 0; i < maxn; i++)
		if(degree[i] != 0)
			d.push_back(degree[i]);
	return d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1));
}

int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		memset(G, 0, sizeof(G));
		memset(showed, 0, sizeof(showed));
		memset(degree, 0, sizeof(degree));
		memset(visited, 0, sizeof(visited));
		int u;
		while(N--)
		{
			string s;
			cin >> s;
			int start = s[0] - 'a', last = s[s.size() - 1] - 'a';
			u = start;
			G[start][last]++;
			G[last][start]++;
			showed[start] = 1;
			showed[last] = 1;
			degree[start]++;
			degree[last]--;
		}
		if(degree_fit() && is_connect(u))
			cout << "Ordering is possible.\n";
		else
			cout << "The door cannot be opened.\n";
	}
	return 0;
}

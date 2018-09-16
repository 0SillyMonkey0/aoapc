#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 26;
vector<int> G[maxn];

int min_band, seq[maxn];

void dfs(int *A ,int cur, int n, string &nodes)
{
	if(cur == n)
	{
//		for(int i = 0; i < n; i++)
//		{
//			cout << (char)(A[i] + 'A') << " ";
//			if(i == n - 1 )
//				cout << "\n";
//		}
		int band = 0;
		for(int i = 0; i < n; i++)
		{
			int max_band = 0;
			int node = A[i];
			for(int j = 0; j < G[node].size(); j++)
			{
				for(int idx = 0; idx < n; idx++)
					if(A[idx] == G[node][j])
					{
						if(abs(idx - i) > max_band)		
							max_band = abs(idx - i);
//						cout << "I == " << i << " idx ==" << idx <<" J == " << (char)(A[idx] + 'A') << " max band is: " << max_band << endl; 
						break;
					}
			}
			if(max_band > band)
				band = max_band;
		}
		if(band < min_band)
		{
			min_band = band;
			copy(A, A + n, seq);
		 } 
		
	}
	else
	{
		for(int i = 0; i < nodes.size(); i++)
		{
			int ok = 1;
			for(int j = 0; j < cur; j++)
				if(A[j] == nodes[i] - 'A')
					ok = 0;
			if(ok)
			{
				A[cur] = nodes[i] - 'A';
				dfs(A, cur + 1, n, nodes);
			}
			
		}
	}
	
}

int main()
{
	string s;
	while(cin >> s, s != "#")
	{
		for(int i = 0; i < maxn; i++)
			G[i].clear();
		string nodes;
		for(int i = 1; i < s.size(); i++)
		{
			if(s[i] == ':')
			{
				for(int j = i + 1; s[j] != ';' && j < s.size(); j++)
				{
					G[s[i - 1] - 'A'].push_back(s[j] - 'A');
					G[s[j] - 'A'].push_back(s[i - 1] - 'A');
				}			
			}	
		}
		for(int i = 0; i < maxn; i++)
			if(G[i].size() != 0)
				nodes.push_back(i + 'A');
		
//		for(int i = 0; i < nodes.size(); i++)
//		{
//			cout << nodes[i] << ": ";
//			int node = nodes[i] - 'A';
//			for(int j = 0; j < G[node].size(); j++)
//				cout << (char)(G[node][j] + 'A')<< " ";
//			cout << "\n";
//		}
		
		min_band = 100;
		int A[maxn];
		dfs(A, 0, nodes.size(), nodes); 

		for(int i = 0; i < nodes.size(); i++)
			cout << (char)(seq[i] + 'A' ) << " ";
		cout << "-> " << min_band << endl;
	}
}

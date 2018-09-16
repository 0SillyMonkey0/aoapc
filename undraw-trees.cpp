#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int maxn = 200 + 10;
char tree[maxn][maxn];
int n;

void dfs(int r, int c)
{
	cout << tree[r][c] << "(";
	if(r + 1 < n && tree[r + 1][c] == '|')
	{
		int i = c;
		while(i >= 1 && tree[r + 2][i - 1] == '-') i--;
		while(tree[r + 2][i] == '-' && tree[r + 3][i] != '\0')
		{
			if(!isspace(tree[r + 3][i]))
				dfs(r + 3, i);
			i++;
		} 
	}
	cout << ")";
}

void solve()
{
	n = 0;
	for(;;)
	{
		fgets(tree[n], maxn, stdin);
		if(tree[n][0] == '#') break;
		n++;
	}
	cout << "(";
	if(n)
	{
		for(int i = 0; i < strlen(tree[0]); i++)
		{
			if(tree[0][i] != ' ')
			{
				dfs(0, i);
				break;
			 } 
		} 
	}
	cout << ")\n";
}

int main()
{
	int T;
	cin >> T; cin.get();
	while(T--)
		solve();
	return 0;
}

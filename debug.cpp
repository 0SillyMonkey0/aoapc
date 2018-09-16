#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

fstream out("debug.txt");
const int maxn = 1000 + 5;
string s1, s2;
int d[maxn][maxn], vis[maxn][maxn];

int dp(int i, int j)
{
	if(vis[i][j])
		return d[i][j];
	if(i < 0 || j < 0)
		return 0;
	vis[i][j] = 1;
	
	
	if(s1[i] == s2[j])
		d[i][j] = dp(i - 1, j - 1) + 1;
	else
		d[i][j] = max(dp(i - 1, j), dp(i, j - 1));
	
	return d[i][j];
}

int main()
{	
	while(cin >> s1 >> s2)
	{
		memset(vis, 0, sizeof(vis));
		int len1 = s1.size(), len2 = s2.size();
		out << dp(len1 - 1, len2 - 1) << endl;
	}
}

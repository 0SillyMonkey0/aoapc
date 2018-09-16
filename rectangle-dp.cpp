#include <iostream>
#include <cstring>
 
using namespace std;

const int maxn = 100;
int G[maxn][maxn], d[maxn];

struct rect{
	int len, wid;
}r[maxn];

bool is_fit(rect r1, rect r2)
{
	return (r1.len < r2.len && r1.wid < r2.wid) || (r1.len < r2.wid && r1.wid < r2.len);
}

int n;

int dp(int i)
{
	int& ans = d[i];
	if(ans > 0) return ans;
	ans = 1;
	for(int j = 1; j <= n; j++)
		if(G[i][j]) ans = max(ans, dp(j) + 1);
	return ans;
}

void print_ans(int i)
{
	cout << i << " ";
	for(int j = 1; j <= n; j++)
		if(G[i][j] && d[i] == d[j] + 1)
		{
			print_ans(j);
			break;
		}
}

int main()
{
	cin >> n;
	memset(G, 0, sizeof(G));
	memset(d, -1, sizeof(d));
	for(int i = 0; i < n; i++)
	{
		cin >> r[i].len >> r[i].wid;
		for(int j = 0; j < i; j++)
		{
			if(is_fit(r[i], r[j]))
				G[i][j] = 1;
			if(is_fit(r[j], r[i]))
				G[j][i] = 1;
		}
	}	
	int ans = -1, idx = -1;
	for(int i = 0; i < n; i++)
	{
		int tmp = dp(i);
		if(tmp > ans)
		{
			ans = tmp;
			idx = i;
		}
	}
	cout << ans << endl;
	print_ans(idx);
} 

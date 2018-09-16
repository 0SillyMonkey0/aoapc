#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
int num[maxn][maxn], d[maxn][maxn];
int n;

int solve(int i, int j)
{
	if(i == n)
		return 0;
	if(d[i][j] >= 0)
		return d[i][j];
	return d[i][j] = num[i][j] + max(solve(i + 1, j), solve(i + 1, j + 1));
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
			cin >> num[i][j];
	}
	memset(d, -1, sizeof(d));
	cout << solve(0, 0);
	return 0;
}

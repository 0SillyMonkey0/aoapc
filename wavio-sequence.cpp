#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 5;
int num[maxn], d1[maxn], d2[maxn], dp[maxn];

int main()
{
	int n;
	while(cin >> n)
	{
		memset(d1, -1, sizeof(d1));
		memset(d2, -1, sizeof(d2));
		memset(dp, 0, sizeof(dp));
		
		for(int i = 0; i < n; i++)
			cin >> num[i];
		
		dp[0] = num[0];
		d1[0] = 1;
		int len = 0;
		for(int i = 1; i < n; i++)
		{
			if(num[i] > dp[len])
			{
				len++;
				dp[len] = num[i];
				d1[i] = len + 1;
			}
			else
			{
				int pos = lower_bound(dp, dp + len, num[i]) - dp;
				d1[i] = pos + 1;
				dp[pos] = num[i];
			}
			
		}
		
		len = 0;
		dp[0] = num[n - 1];
		for(int i = n - 2; i >= 0; i--)
		{
			if(num[i] > dp[len])
			{
				len++;
				dp[len] = num[i];
				d2[i] = len + 1;				
			}
			else
			{
				int pos = lower_bound(dp, dp + len, num[i]) - dp;
				d2[i] = pos + 1;
				dp[pos] = num[i];
			}
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, min(d1[i], d2[i]));
		cout << 2*ans - 1 << endl;
	}
	return 0;
}

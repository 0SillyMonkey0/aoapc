#include <iostream>

using namespace std;

const int maxn = 32 + 5;
int n, A[maxn], isp[maxn], vis[maxn] = { 0 };

bool is_prime(int n)
{
	for(int i = 2; i <= n / 2; i++)
		if(n % i == 0)
			return false; 
	return true;
} 

void dfs(int cur)
{
	if(cur == n && isp[A[0] + A[n - 1]])
	{
		for(int i = 0; i < n; i++)
			cout << A[i] << (i == n - 1 ? "\n" : " ");
	}
	
	else
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i] && isp[i + A[cur - 1]])
		{
			A[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	int count = 0;
	A[0] = 1;
 	while(cin >> n)
	{
		for(int i = 2; i < 2 * n; i++) isp[i] = is_prime(i);
		if(count != 0)
			cout << "\n";
		cout << "Case " << ++count << ":\n";
		dfs(1);
	
	}
	
}

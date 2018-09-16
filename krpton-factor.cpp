#include <iostream>

using namespace std;

const int maxn = 100;
int L, n, s[maxn], cnt = 0;

void dfs(int cur)
{
	if(cnt > n)
		return;
	if(cnt == n)
	{
		int group = 0;
		for(int i = 0; i < cur; i++)
		{
			cout << (char)('A' + s[i]);
			if((i + 1) % 64 == 0 && i != cur - 1)
				cout << "\n";
			else if((i + 1) % 4 == 0 && i != cur -1)
				cout << " ";
		}	
		cout << "\n";
		cout << cur << "\n";
		return;
	}
	else
	{
		for(int i = 0; i < L; i++)
		{
			int ok = 1;
			s[cur] = i;
			for(int j = 1; j*2 <= cur + 1; j++)
			{
				int equal = 1;
				for(int k = 0; k < j; k++)
				{
					if(s[cur - k] != s[cur - j - k])
					{
						equal = 0;
						break;
					}
				}
				if(equal)
				{
					ok = 0;
					break;
				}	
			}
			if(ok)
			{
				cnt++;
				dfs(cur + 1);
			}
			
		}
	}
}

int main()
{
	while(cin >> n >> L, L != 0)
	{
		cnt = 0;
		dfs(0);
	}
}

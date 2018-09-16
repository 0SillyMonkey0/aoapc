#include <iostream>
#include <algorithm>

using namespace std;

long long ans;
const int maxn = 20;
int s[maxn];

int main()
{
	int n;
	int count = 0;
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
			cin >> s[i];
		long long maxans = -1000;
		for(int i = 0; i < n; i++)
		{
			ans = s[i];
			if(ans > maxans)
				maxans = ans;
			for(int j = i + 1; j < n; j++)
			{
				ans *= s[j];
				if(ans > maxans)
					maxans = ans;
			}	
			
		}
		if(maxans < 0)
			maxans = 0;
		
		cout << "Case #" << ++count <<": The maximum product is " << maxans << "." << "\n\n";
	}
	return 0;
}

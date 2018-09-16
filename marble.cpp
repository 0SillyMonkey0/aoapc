#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10000;

int main()
{
	int n, q, T = 0;
	while(~scanf("%d%d", &n, &q))
	{
		int mar[maxn] = { 0 }, ques[maxn] = { 0 };
		for(int i = 0; i < n; i++)
			scanf("%d", &mar[i]);
			
		sort(mar, mar + n);
		
		for(int i = 0; i < q; i++)
			scanf("%d", &ques[i]);
			

		printf("CASE# %d:\n", ++T);
		
		for(int i = 0; i < q; i++)
		{
			int p = lower_bound(mar, mar + n, ques[i]) - mar;
			if(mar[p] == ques[i]) printf("%d found at %d\n", ques[i], p + 1);
			else printf("%d not found\n", ques[i]);
		} 
	}
	return 0;
}

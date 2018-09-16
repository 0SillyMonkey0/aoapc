#include <stdio.h>
#define maxn 1000005

int ans[maxn] = {0};
int main()
{
	for(int i = 1; i < maxn; ++i)
	{
		int x = i, y = i;
		while(x > 0)
		{
			y += x % 10;
			x /= 10;
		}
		if(ans[y] == 0)
		ans[y] = i;
	}
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}

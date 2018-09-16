#include <stdio.h>
#define maxn 25

int queue[maxn] = {0};
int n, k, m;
int go(int s, int sign, int step)
{
	while(step--)
	{
		s = (s + sign + n - 1) % n + 1;
		if(queue[s] == 0)
			step++;
	}
	return s;
}

int main()
{
	while(scanf("%d%d%d", &n, &k, &m) == 3 && n && k && m)
	{
		for(int i = 0; i <= n; i++) queue[i] = 1;
		int left = n;
		int s1 = n, s2 = 1;
		while(left)
		{
			s1 = go(s1, 1, k);
			s2 = go(s2, -1, m);
			printf("%3d", s1);
			left--;
			if(s2 != s1)
			{
				printf("%3d", s2);
				left--;
			}
			queue[s1] = queue[s2] = 0;
			if(left) printf(",");
		}
		printf("\n");
	}
	return 0;
}

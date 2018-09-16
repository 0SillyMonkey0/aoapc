#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int left[maxn], right[maxn];

inline void link(int L, int R) {
  right[L] = R; left[R] = L;
}

int main()
{
	int n, m, kase = 0;
	while((scanf("%d%d", &n, &m)) == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			left[i] = i - 1;
			right[i] = (i+1) % (n+1);
		}
		right[0] = 1; left[0] = n;
		int op, X, Y, inv = 0;
				
		
		while(m--)
		{
			if(m == 0)
				int x = 0;
			scanf("%d", &op);
			if(op == 4)
				inv = !inv;
			else
			{
				scanf("%d%d", &X, &Y);
				if(op != 3 && inv) op = 3 - op;
				if(right[Y] == X && op == 3)
						swap(X, Y);
				int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
				if(op == 1)
				{
					if(X == left[Y]) continue;
					link(LX, RX); link(LY, X); link(X, Y);	
//					printf("cao");
//					for(int i = 1, b = 0; i <= n; i++)
//					{
//						b = right[b];
//						printf("%d ", b);
//					} 
//					printf("\n");									
				}
				else if(op == 2)
				{
					if(X == right[Y]) continue;
					link(LX, RX);
					link(X, RY);
					link(Y, X);
//					printf("mmp");
//					for(int i = 1, b = 0; i <= n; i++)
//					{
//						b = right[b];
//						printf("%d ", b);
//					} 
//					printf("\n");
				}
				else if(op == 3)
				{
					
					if(right[X] == Y)
					{
						
						
						link(LX, Y);
						link(Y, X);
						link(X, RY);
						
						
//						printf("ri");
//						for(int i = 1, b = 0; i <= n; i++)
//						{
//							b = right[b];
//							printf("%d ", b);
//						} 
//						printf("\n");						
					}
					else
					{
						link(LX, Y); 
						link(Y, RX); 
						link(LY, X);
						link(X, RY);
//						printf("gan");
//						for(int i = 1, b = 0; i <= n; i++)
//						{
//							b = right[b];
//							printf("%d ", b);
//						} 
//						printf("\n");						
					}
				}
			}
		}
		int b = 0;
		long long ans = 0;
		for(int i = 1; i <= n; i++)
		{
			b = right[b];
			if(i % 2 == 1) ans += b;
		} 
		
		if(inv && n % 2 == 0) ans = (long long)n*(n+1)/2 - ans;
    	printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}

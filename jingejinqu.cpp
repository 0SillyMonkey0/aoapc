#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50 + 5;
int d[maxn][maxn * 180 + 678], t[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) 
	{
        
		memset(d, 0, sizeof(d));
		int time, n;
	    scanf("%d%d", &n, &time);
	    for(int i = 0; i < n; i++) 
			scanf("%d", &t[i]);
			
		for(int i = 0; i < time; i++)
		{
			d[0][i] = -100000;
			d[0][t[0]] = 1;
		    d[0][0] = 0;
		}
	  
		for(int i = 1; i < n; i++)
			for(int j = 0; j < time; j++)
			{
				int a = d[i - 1][j];
				int b = -1;
				if(j - t[i] >= 0)
					b = d[i - 1][j - t[i]] + 1;
				d[i][j] = max(a, b);
			}
		
//		for(int i = 0; i < n; i++)
//			for(int j = 0; j < time; j++)
//			{
//				cout << d[i][j] << " ";
//				if(j == time)
//					cout << "\n";
//			}
		
		int num = 0, song_time = 0;
		for(int i = time; i >= 0; i--)
		{
			if(d[n - 1][i] > num)
			{
				num = d[n - 1][i];
				song_time = i;
			}
		}
		num++;
		song_time += 678;
		printf("Case %d: %d %d\n",kase,num,song_time);
	}
}

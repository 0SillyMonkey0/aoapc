#include <stdio.h>

#define maxn 20 

int main()
{
	int T = 0;
	int n, edge;
	while(~(scanf("%d%d", &n, &edge)))
	{
		int v[maxn][maxn] = {0}, h[maxn][maxn] = {0};
		for(int i =  0; i < edge; i++)
		{
			char ch;
			int j, k;
			scanf(" %c%d%d", &ch, &j, &k);
			if(ch == 'V')
				v[k][j] = 1;
			else
				h[j][k] = 1;
		}

		if (T++) printf("\n**********************************\n\n");  
    		printf("Problem #%d\n\n",T);  
    		
    	int sum = 0;
		for(int size = 1; size <= n; size++)
		{
			int count = 0;
			for(int i = 1; i + size <= n; i ++)
				for(int j = 1; j + size <= n; j++)
				{
					int flag = 1;
					for(int k = j; k  < j + size; k++)
						if(!(h[i][k] && h[i + size][k]))
						{
							flag = 0;
							break;								
						}
					
					for(int k = i; k < i + size; k++)
					{
						if(!flag)
							break;
						if(!(v[k][j] && v[k][j + size])) 
						{
							flag = 0;
							break;
						}
					}
						
					count += flag;
				}
			sum += count;
			if (count) printf("%d square (s) of size %d\n",count,size);  
		}
		if (!sum) printf("No completed squares can be found.\n");  
	}
	
	
} 

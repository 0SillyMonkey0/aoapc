#include <stdio.h>

#define n 1005

int main()
{
	int num = 0;
	while(~scanf("%d", &num))
	{		
		int ip[n][4] = {0};
		for(int i = 0; i < num; i++)
			scanf("%d.%d.%d.%d", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
			
		int pos = 0;
		for(; pos < 4; pos++)
		{
			int flag = 1;
			for(int i = 0; i < num; i++)
				if(ip[i][pos] != ip[0][pos])
				{
					flag = 0;
					break;
				}
			if(!flag)
			break;
		}
		
		int ppos = 7;
		for(; ppos >= 0; ppos--)
		{
			int flag = 1;
			for(int i = 0; i < num; i++)
				if(ip[i][pos] >> (ppos) != ip[0][pos] >> (ppos))
				{
					flag = 0;
					break;
				}
			if(!flag)
			break;
		}
		ppos = ppos + 1;
		
	
		int mask[4] = {0};
		for(int i = 0; i < pos; i++)
			mask[i] = 255;
		mask[pos] = (255 << ppos) & 255;
		for(int i = pos + 1 ; i < 4; i++)
			mask[i] = 0;
		
		for(int i = 0; i < 3; i++)
			printf("%d.", mask[i] & ip[0][i]);
		printf("%d\n", mask[3] & ip[0][3]);
		
		for(int i = 0; i < 3; i++)
			printf("%d.", mask[i]);
		printf("%d\n", mask[3]);
	}
	return 0;
}

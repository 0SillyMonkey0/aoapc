#include <cstdio>
#include <algorithm>

int main()
{
	char dice[12] = {0};
	while(scanf("%s", dice) == 1)
	{
		char dice1[6], dice2[6];
		for(int i = 0 ; i < 6; i++)
			dice1[i] = dice[i];
		for(int i = 0 ; i < 6; i++)
			dice2[i] = dice[i + 6];
		
		int cnt = 0;
		int vis[3] = {0};
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(!vis[j] && ((dice1[i] == dice2[j] && dice1[5-i] == dice2[5-j]) || (dice1[i] == dice2[5-j] && dice1[5-i] == dice2[j] )))
				{
					cnt++;
					vis[j] = 1;
					break;
				}
			}	
		}	
		
		cnt == 3? puts("TRUE") : puts("FALSE");
	}
	return 0; 
}

#include <stdio.h>
#include <string.h>

#define maxn 1000

int main()
{
	for(;;)
	{
		int rnd, flag[maxn] = {0}, times = 0;
		char right[maxn] = {0}, guess[maxn] = {0};
		scanf("%d", &rnd);
		if(rnd == -1)
			break;
			
		scanf("%s%s", right, guess);
		int lenr = strlen(right), leng = strlen(guess);
		for(int i = 0; i < leng; i++)
		{
			int good_guess = 0;
			for(int j = 0; j < lenr; j++)
			{
				if(right[j] == guess[i])
				{
					flag[j] = 1;
					good_guess = 1;
				}	
			}
			if(!good_guess)
				times++;
		}
		int win = 1, chick = 0, lose = 0;
		if(times > 6)
		{
			lose = 1;
			win = 0;	
		}
		else
		{
			for(int i = 0; i < lenr; i++)
			{
				if(flag[i] == 0)
				{
					win = 0;
					chick = 1;	
				}
			}
		}
		printf("Round %d\n", rnd);
		if(win)
			printf("You win\n");
		else if(chick)
			printf("You chickened out\n");
		else
			printf("You lose\n"); 
			
	}	
	return 0;
}

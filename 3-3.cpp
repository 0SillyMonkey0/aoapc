#include <stdio.h>
#include <string.h>
int main()
{
	int T;
	scanf("%d", &T);
	
	while(T--)
	{
		int num[10] = {0};
		int n;
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++)
		{
			char cnum[10] = {0};
			sprintf(cnum, "%d", i);
			int len = strlen(cnum);
			for(int j = 0; j < len; j++)
				num[cnum[j] - '0'] += 1;
		}
		
		for(int i = 0; i < 10; i++)
		{
			printf("%d", num[i]);
			if(i != 9)
				printf(" ");
		}	
		printf("\n");
	}
	return 0;
}

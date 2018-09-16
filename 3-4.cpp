#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char s[90] ={0};
		scanf("%s", s);
		
		int len = strlen(s);
		for(int i = 1; i <= len; i++)
		{
			if(len % i != 0)
				continue;
			int times = len / i;
			int flag = 1;
			for(int j = 1; j < times; j++)
			{
				for(int k = 0; k < i; k++)
				{
					if(s[k] != s[k + i*j])
					{
						flag = 0;
						break;
					}
				}
			}
			if(flag)
			{
				printf("%d\n", i);
				if(T) puts("");  //why
				break;
			}
		}
	}	
	return 0;
}

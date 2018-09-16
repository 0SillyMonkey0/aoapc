#include <stdio.h>
#include <string.h>
#define maxn 3005
int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) == 2)
	{
		int pria[maxn], res[maxn], pos = 0, dec, begin = 0, end = 0, flag = 1, aa = a;
		dec = a / b;
		a = (a - dec*b) * 10;
		pria[pos] = a;
		for(int count = 0; count < maxn; count++)
		{
			for(int i = 0; i < 10; i++)
			{
				if(b*i <= a && b*(i + 1) > a)
				{
					res[pos++] = i;
					a -= b*i;
					a *= 10;
					pria[pos] = a;
					break;
				}
			}
			
			for(int j = 0; j < count; j++)
			{
				if(pria[j] == a)
				{
					begin = j;
					end = count;
					flag = 0;
					break;
				}
			}	
			if(!flag)
				break;
		}
		
		printf("%d/%d = %d.",aa, b, dec);
		for(int i = 0; i <= end; i++)
		{
			if(i == begin)
				printf("(");
			printf("%d", res[i]);
			if((i == begin && res[begin] == res[end]))
				break;
			if(i == 49)
			{
				printf("...");
				break;
			}
			
		}	
		printf(")\n\t%d = number of digits in repeating cycle\n", end - begin + 1);
	}
	
	
	
}

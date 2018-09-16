#include <stdio.h>
#include <string.h>
#define maxn 100
int main()
{
	char s[maxn];
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int score = 0, con = 0;
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i < len; i++)
		{
			if(s[i] == 'O') 
			{
				con++;
				score += con;
			}
			else con = 0;
		}
		printf("%d\n", score);
	}
	return 0;
}

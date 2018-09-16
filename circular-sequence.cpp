#include <stdio.h>
#include <string.h>
#define maxn 105


int is_less(char* s, int p,  int q)
{
	int len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		if(s[(p + i) % len] != s[(q + i) % len])
			return s[(p + i) % len] < s[(q + i) % len];
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	char gene[maxn];
	while(n--)
	{
		int ans = 0;
		scanf("%s", gene);
		int len = strlen(gene);
		for(int pos = 0; pos < len; pos++)
		{
			if(is_less(gene, pos, ans)) ans = pos;
		}
		
		for(int i = 0; i < len; i++) printf("%c", gene[(ans + i) % len]);
		printf("\n");
	}
	
	return 0;
}

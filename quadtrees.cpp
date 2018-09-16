#include <iostream>
#include <cstring>
const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len], cnt;

void draw(const char* s, int& p, int a, int b, int c, int d)
{
	char ch = s[p++];
	if(ch == 'p')
	{
		draw(s, p, (a + c)/2, (b + d)/2, c, d); //1
		draw(s, p, a, (b + d)/2, (a + c)/2, d);  //2
		draw(s, p, a, b, (a + c)/2, (b + d)/2);  //3
		draw(s, p, (a + c)/2, b, c, (b + d)/2);   //4
	}
	else if(ch == 'f')
	for(int i = a; i < c; i++)
		for(int j = b; j < d; j++)
			if(buf[i][j] == 0)
			{
				buf[i][j] = 1;
				cnt++;
			}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		for(int i = 0; i < 2; i++)
		{
			scanf("%s", s);
			int p = 0;
			draw(s, p, 0, 0, len, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}

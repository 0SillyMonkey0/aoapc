#include <stdio.h>

int main()
{
	int c, left = 1;
	while((c = getchar()) != EOF)
	{
		if(c == '"')
		{
			printf("%s", left ?  "``" : "''");
			left = 0;
		}
		else printf("%c", c);
	}
	return 0;
}

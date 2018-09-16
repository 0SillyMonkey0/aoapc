#include <stdio.h>

int main()
{
	int f;
	scanf("%d", &f);
	printf("%.3f", 5 * ((float)f - 32) / 9);
	
	return 0;
}

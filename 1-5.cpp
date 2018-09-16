#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if(n * 95 >= 300)
		printf("%.2f", 0.85 * n * 95);

	else
		printf("%.2f", (float)n * 95);
		
		
	return 0;
}

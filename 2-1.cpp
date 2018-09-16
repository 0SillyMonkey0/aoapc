#include <stdio.h>

int main()
{
	
	for(int num = 1; num < 1000; ++num)
	{
		int a = num%10;
		int b = num/10%10;
		int c = num/100;-----------------
		
		if(a*a*a + b*b*b + c*c*c == num)
			printf("%d\n", num); 
			
		
	}
	return 0;
}

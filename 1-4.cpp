 #include <stdio.h>
 #include <math.h>
 
 #define pi 3.1415926
 int main()
 {
 	int n;
 	scanf("%d", &n);
 	printf("%f %f", sin(pi * (float)n / 180), cos(pi * (float)n / 180));
 	
 	return 0;
 }

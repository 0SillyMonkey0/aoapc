#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	double n, m ;
	while(1)
	{
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;
		double sum = 0;
		for(double i = n; i <= m; i = i + 1.0)
		{
			double fac = i * i;
			sum += 1.0/fac;
		}	
		
			
		printf("%.5f", sum);
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
	double a, b;
	int c;
	while(1)
	{
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0)
			break;
			
		cout<< setiosflags(ios::fixed)<<setprecision(c)<< a/b <<endl;
	}
	
	
}

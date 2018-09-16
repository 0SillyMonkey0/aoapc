#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	for(int i = 100; i < 333; ++i)
	{
		int a = i, b = 2*i, c = 3*i;
		int num[9] = {a%10, a/10%10, a/100, b%10, b/10%10, b/100, c%10, c/10%10, c/100};
		sort(num, num + 9);
		int flag = 1;
		for(int j = 1; j < 10; ++j)
		{
			if(num[j - 1] != j)
				flag = 0;
			
		}
		if(flag)
			cout << a << " " << 2*a << " " << 3*a << endl;
	}
	return 0;
}

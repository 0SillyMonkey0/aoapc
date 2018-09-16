#include <iostream>

using namespace std;

int main()
{
	int ugly_num[1500] = { 1 };
	
	for(int i = 1; i < 1500; i++)
	{
		int t2 = 0, t3 = 0, t5 = 0;
		while(ugly_num[t2] * 2 <= ugly_num[i - 1]) t2++;
		while(ugly_num[t3] * 3 <= ugly_num[i - 1]) t3++;
		while(ugly_num[t5] * 5 <= ugly_num[i - 1]) t5++;
		
		int tmp = ugly_num[t2] * 2;
		if(ugly_num[t3] * 3 < tmp) tmp = ugly_num[t3] * 3;
		if(ugly_num[t5] * 5 < tmp) tmp = ugly_num[t5] * 5;
		
		ugly_num[i] = tmp;
	}
	
	cout << ugly_num[1499] << endl;
	return 0;
}

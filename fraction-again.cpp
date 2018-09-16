#include <iostream>

using namespace std;

int main()
{
	int k;
	while(cin >> k)
	{
		int x, y, count = 0;
		
		for(y = k + 1; y <= 2*k; y++)
			if(k*y % (y - k) == 0)
				count++;
		cout << count << endl;
		for(y = k + 1; y <= 2*k; y++)
			if(k*y % (y - k) == 0)
			{
				x = k*y / (y - k);
				cout << "1/" << k << " = " << "1/" << x << " + " << "1/" << y << "\n";
			}
	}
	return 0;
}

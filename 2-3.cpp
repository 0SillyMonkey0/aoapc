#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int col = (n - 1) * 2 + 1;
	for(int i = 1; i <= n; ++i )
	{
		for(int j = 0; j < i - 1; ++j)
			cout << " ";
			
		for(int j = 0; j < col - 2*(i - 1); ++ j)
			cout << "#";
			
		for(int j = 0; j < i - 1; ++j)
			cout << " ";
			
		cout << endl;
	}
	return 0;
}

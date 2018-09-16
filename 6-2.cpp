#include <iostream>

using namespace std;

const int maxn = 1 << 10;
int leaf[maxn];
int main()
{
	int n, count  = 1;
	while(cin >> n, n != 0)
	{
		cout << "S-Tree #" << count << ":\n";
		count++;
		string s;
		
		for(int i = 0; i < n; i++)
			cin >> s;
		int m = 1 << n;
		cin >> s;
		for(int i = 0; i < m; i++)
			leaf[m + i] = s[i] - '0';
			 
	
		int t;
		cin >> t;
		for(int i = 0; i < t; i++)
		{
			string s;
			cin >> s;
			int pos = 1;
			for(int i = 0; i < n; i++)
			{
				if(s[i] == '0')
					pos *= 2;
				else if(s[i] == '1')
					pos = pos*2 + 1;
			}
			cout << leaf[pos];
		}
		cout << "\n\n";
	}
}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n !=0)
	{
		stack<int> s;
		vector<int> target(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> target[i];
		int current = 1;
		for(int i = 1; i <= n; i++)
		{
			s.push(i);
			while(!s.empty() && s.top() == target[current])
			{
				s.pop();
				current++;
			}
		}
		if(current == n + 1) cout << "YES\n";
		else cout << "NO\n";
		
	}
}

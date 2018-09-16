#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin >> T; cin.get();
	while(T--)
	{
		stack<char> pa;
		string s;
		getline(cin, s);
		if(s.empty())
		{
			cout << "Yes\n";
			continue;
		}
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == ')')
			{
				if(!pa.empty() && pa.top() == '(')
					pa.pop();
				else
				{
					pa.push(s[i]);
					break;
				}
			}
			else if(s[i] == ']')
			{
				if(!pa.empty() && pa.top() == '[')
					pa.pop();
				else
				{
					pa.push(s[i]);
					break;
				}
			}
			else if(s[i] == '(' || s[i] == '[')
				pa.push(s[i]);
		}
		if(pa.empty()) 
			cout << "Yes\n";
		else 
			cout << "No\n";
	}
	return 0;
}

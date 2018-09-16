#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct matrix{
	int a, b;
	matrix(int a = 0, int b = 0):a(a), b(b) {}
} m[26];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		int k = name[0] - 'A';
		cin >> m[k].a >> m[k].b;
	}
	
	string expr;
	while(cin >> expr)
	{
		stack<matrix> s;
		int times = 0;
		int error = 0;
		for(int i = 0; i < expr.size(); i++)
		{
			if(expr[i] == ')')
			{
				matrix m2 = s.top(); s.pop();
				matrix m1 = s.top(); s.pop();
				if(m1.b != m2.a)
				{
					error = 1;
					cout << "error\n";
					break;
				}
				times += m1.a * m1.b * m2.b;
				s.push(matrix(m1.a, m2.b));
			}
			else if(isalpha(expr[i]))
				s.push(m[expr[i] - 'A']);
		}
		if(!error)
			cout << times << endl;
	}
	return 0;
}

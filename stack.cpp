#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef set<int> Set;
vector<Set> Setcache;
map<Set, int> IDcache;
int ID(Set x)
{
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	IDcache[x] = Setcache.size() - 1;
	return IDcache[x];
}

int main()
{
	stack<int> s;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		
		if(op[0] == 'P') s.push(ID(Set()));
		else if(op[0] == 'D') s.push(s.top());
		else
		{
			Set x1 = Setcache[s.top()]; 
			s.pop();
			Set x2 = Setcache[s.top()];
			s.pop();
			Set x;
			if(op[0] == 'U') set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
			if(op[0] == 'I') set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
			if(op[0] == 'A') 
			{
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
}
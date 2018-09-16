#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	for(;;)
	{
		int n;
		cin >> n;
		if(!n)
			break;
			
		map<pair<int, int>, int> ex;
		ex.clear();
		for(int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			pair<int, int> stu = make_pair(a, b);
			pair<int, int> want = make_pair(b, a); 
			if(ex.count(stu))
				ex[stu]++;
			else
				ex[stu] = 1;
				
			if(ex.count(want) && ex[want] != 0)
			{
				ex[stu]--;
				ex[want]--;
			}
		}
		int flag = 1;
		for(map<pair<int, int>, int>::iterator it = ex.begin(); it != ex.end(); it++)
			if(it->second)
			{
				flag = 0;
				cout << "NO\n";
				break;
			}
		if(flag)
			cout <<"YES\n";
	}
}

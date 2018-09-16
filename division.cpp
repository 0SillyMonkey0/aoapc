#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int first = 0;
	while(cin >> n, n != 0)
	{
		int mark = 0;
		if(first)
			cout << "\n";
		for(int i = 1234; i < 50000; i++)
		{
			int fflag = 0;
			int flag[10] = { 0 };
			string s = to_string(i);
			if(s.size() == 4)
				flag[0] = 1;
			for(int j = 0; j < s.size(); j++)
				if(flag[s[j] - '0'] == 0)
					flag[s[j] - '0'] = 1;
				else
					{
						fflag = 1;
						break;
					}
			if(fflag)
				continue;
			int fenzi = n * i;
			string ss = to_string(fenzi);
			for(int j = 0; j < ss.size(); j++)
				if(flag[ss[j] - '0'] == 0)
					flag[ss[j] - '0'] = 1;
				else
					{
						fflag = 1;
						break;
					}
			if(fflag)
				continue;
			for(int i = 0; i < 10; i++)
				if(flag[i] != 1)
					fflag = 1;
			if(fflag)
				continue;
			mark = 1;
			cout << fenzi << " / ";
			if(s.size() == 4)
				cout << 0;
			cout << s << " = " << n << endl;
		}
		if(!mark)
			cout << "There are no solutions for " << n << ".\n";
		first = 1;
	}
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<vector<int>, int> id;
int cnt = 0;
int ID(const vector<int> &se)
{
	if(!id.count(se))
		id[se] = cnt++;
	return id[se];
	 
}

bool is_zero(const vector<int> &se)
{
	for(vector<int>::const_iterator it = se.begin(); it != se.end(); it++)
		if(*it)
			return false;
	return true;
}


int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int len;
		cin >> len;
		vector<int> seq;
		map<int, int> ducci;
		for(int i = 0; i < len; i++)
		{
			int num;
			cin >> num;
			seq.push_back(num);
		}	
		ducci[ID(seq)] = 1;
		for(int i = 0; i < 1000; i++)
		{
			vector<int> tmp = seq;
			for(int i = 0; i < len; i++)
				seq[i] = abs(tmp[i] - tmp[(i + 1) % len]);
			
			if(is_zero(seq))
			{
				cout << "ZERO" << endl;
				break;
			}
			
			if(ducci.count(ID(seq)))
			{
				cout << "LOOP" << endl;
				break;
			}
			ducci[ID(seq)] = 1;
		}
	}
	
	return 0;
}

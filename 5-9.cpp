#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int bug = 0;
map<string, int > arr_len;
map<string, map<int, int> > arr_val;

int get_size(const string& s)
{
	string::const_iterator it = find(s.begin(), s.end(), '[');
	return stoi(string(it + 1, s.end() - 1));
}

string get_name(const string& s)
{
	string::const_iterator it = find(s.begin(), s.end(), '[');
	return string(s.begin(), it);
}

int get_value(string s)
{
	if(isdigit(s[0]))
		return stoi(s);
	else
	{
		string::iterator it = find(s.begin(), s.end(), '[');
		string subs = string(it + 1, s.end() - 1);
		int ind = get_value(subs);
		string name = get_name(s);
		if(arr_len.count(name) == 0 || arr_len[name] <= ind || arr_val[name].count(ind) == 0)
		{
			bug = 1;
			return 0;
		}
		return arr_val[name][ind];
	}
}

int main()
{
	int flag = 0;
	int line = 0, bugline = 0;
	for(;;)
	{
		string s;
		cin >> s;
		if(s != ".")
		{
			flag = 0;
			line++;
			string::iterator it = find(s.begin(), s.end(), '=');
			if(it == s.end())          //declare
			{
				int len = get_size(s);
				string name = get_name(s); 
				arr_len[name] = len;
				arr_val[name].clear();
			}	
			else                       //assign
			{
				string left(s.begin() + 2, it - 1), right(it + 1, s.end());
//				cout << "left = " + left << " right = " + right << endl;
				string name = get_name(string(s.begin(), it));
				int ind = get_value(left), val = get_value(right);

				if(!bug)
				{
					if(arr_len.count(name) == 0 || ind >= arr_len[name])
					{
						bug = 1;
//						cout << "hhhh";
					}	
				}
				if(bug && !bugline)
					bugline = line;
				
				if(bug)
					continue;
				arr_val[name][ind] = val;
			}			
		}
		else
		{
			if(flag)
				break;
			
			cout << bugline << endl;
			
			arr_len.clear();
			arr_val.clear();
			flag = 1;
			line = 0; 
			bug = 0;
			bugline = 0;
	
			continue;
		}
	}
	return 0;
}

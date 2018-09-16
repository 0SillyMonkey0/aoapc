#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxr = 1000 + 5;

int main()
{
	vector<string> s[maxr];
	string str;
	int row = -1;
	int pos[maxr] = { 0 };
	while(getline(cin, str) && str != "#")
	{
		row++;
		int start = 0, end = -1;
		int col = 0;
		while(start != str.size())
		{
			for(int i = start; i < str.size(); i++)
			{
				start = i;
				if(str[i] != ' ')
					break;
			}
			
			for(int i = start; i < str.size(); i++)
			{
				end = i;
				if(str[i] == ' ')
					break;
			}
			if(end == str.size() - 1)
				end = str.size();
			
			if(start != str.size() - 1)
			{
				string tmp = str.substr(start, end - start);
				s[row].push_back(tmp);	
				pos[col] = max(pos[col], (int)tmp.size());
				col++;
			}
			start = end;
		}
	}
	
	for(int i = 0; i <= row; i++)
	{
		for(int j = 0; j < s[i].size(); j++)
		{
			cout << s[i][j];
			if(j != s[i].size() - 1)
				for(int k = 0; k <= pos[j] - s[i][j].size(); k++)
					cout << ' ';
		}
		if(i != row)
			cout << endl;
	}
	
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> dic[26];
	string s;
	while(cin >> s)
	{
//		if(s == "#")
//			break;
		int m = s[0] - 'a';
		dic[m].push_back(s);
	}
	map<string, int> check;
	vector<string> out;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < dic[i].size(); j++)
		{
			for(int k = j+1; k < dic[i].size(); k++)
			{
				int len = dic[i][j].size();
		
				if(dic[i][k].substr(0, len) == dic[i][j])
				{
					
					int num = dic[i][k][len] - 'a';
					for(int p = 0; p < dic[num].size(); p++)
					{
						if(dic[num][p] == dic[i][k].substr(len, dic[i][k].size() - len))
						{
							if(!check.count(dic[i][k]))
							{
								check[dic[i][k]] = 1;
								out.push_back(dic[i][k]);
							}
						}
						
					}
				}
			}
		}
	}
	sort(out.begin(), out.end());
	for(int i = 0; i < out.size(); i++)
		cout << out[i] << "\n";
	return 0;
}

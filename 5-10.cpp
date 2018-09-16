#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

void pre_pro(string& s)
{
	for(int i = 0; i < s.size(); i++)
		if(!isalpha(s[i]))
			s[i] = ' ';
		else s[i] = tolower(s[i]); 
}

int main()
{
	map<string, set<pair<int, int> > > words;
	vector<vector<string> > passages;
	int N;
	cin >> N;
	cin.get();
	for(int kase = 0; kase < N; kase++)
	{
		vector<string> page;
		int line = -1;
		for(;;)
		{
			string s;
			getline(cin, s);
			line++;	
			if(s == "**********")
				break;
			page.push_back(s);
			pre_pro(s);	
			stringstream ss(s);
			while(ss >> s)
				words[s].insert(make_pair(kase, line));
		}
		passages.push_back(page);
	}
		
	int n;
	cin >> n;
	cin.get();
	for(int i = 0; i < n; i++)
	{
		string ins;
		getline(cin, ins);
		if(ins.find("AND") != string::npos)               //some bugs
		{
			string left, AND, right;
			stringstream ss(ins);
			ss >> left >> AND >> right;
			set<int> l_pas, r_pas, uni;
			for(set<pair<int, int> >::iterator it = words[left].begin(); it != words[left].end(); it++)
				l_pas.insert(it->first);
			for(set<pair<int, int> >::iterator it = words[right].begin(); it != words[right].end(); it++)
				r_pas.insert(it->first);
			set_intersection(l_pas.begin(), l_pas.end(), r_pas.begin(), r_pas.end(), inserter(uni, uni.begin()));
			
			set<pair<int, int> > and_result;
			for(set<pair<int, int> >::iterator it = words[left].begin(); it != words[left].end(); it++)
				if(uni.count(it->first))
					and_result.insert(*it);
			for(set<pair<int, int> >::iterator it = words[right].begin(); it != words[right].end(); it++)
				if(uni.count(it->first))
					and_result.insert(*it);
			int current = and_result.begin()->first, flag = 1;
			for(set<pair<int, int> >::iterator it = and_result.begin(); it != and_result.end(); it++)		
			{
				if(it->first != current)
					cout << "----------\n";
				cout << passages[it->first][it->second] << endl;
				flag = 0;
				current = it->first;
			}
			if(flag)
				cout << "Sorry, I found nothing.\n";
		}
		else if(ins.find("OR") != string::npos)       //some bugs
		{
			string left, OR, right;
			stringstream ss(ins);
			ss >> left >> OR >> right;
			set<pair<int, int> > uni;
			set_union( words[left].begin(), words[left].end(), 
				words[right].begin(), words[right].end(), inserter( uni, uni.begin() ) );
			int flag = 1;
			int current = uni.begin()->first;
			for(set<pair<int, int> >::iterator it = uni.begin(); it != uni.end(); it++)
			{
				if(it->first != current)
					cout << "----------\n";
				
				cout << passages[it->first][it->second] << endl;
				flag = 0;
				current = it->first;
			}
			if(flag)
				cout << "Sorry, I found nothing.\n";	 
		}
		else if(ins.find("NOT") != string::npos)
		{
			string NOT, word;
			stringstream ss(ins);
			ss >> NOT >> word;
			map<int, int> is_on;
			for(set<pair<int, int> >::iterator it = words[word].begin(); it != words[word].end(); it++)
				if(!is_on.count(it->first))
					is_on[it->first] = 1;
			int flag = 1;
			for(int i = 0; i < N; i++)
				if(!is_on.count(i))
				{
					if(!flag)
						cout << "----------\n";
					for(int j = 0; j < passages[i].size(); j++)
						cout << passages[i][j] << "\n";
					flag = 0;
				}
			if(flag)
				cout << "Sorry, I found nothing.\n";
					
		}
		else
		{
			if(words.count(ins))
			{
				int current = words[ins].begin()->first;
				for(set<pair<int, int> >::iterator it = words[ins].begin(); it != words[ins].end(); it++)
				{
					if(it->first != current )
						cout << "----------\n";
					cout << passages[it->first][it->second] << endl;
					current = it->first;
				}	
			}
			else
				cout << "Sorry, I found nothing.\n";
		}
		cout << "==========\n";
	}
	return 0;
}





#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string norm(const string& s)
{
	int len = s.size();
	string ret = s;
	for(int i = 0; i < len; i++)
		ret[i] = tolower(ret[i]);
		
	sort(ret.begin(), ret.end());
	return ret;
}

int main()
{
	string s;
	vector<string> in;
	map<string, int> cnt;
	while(cin >> s)
	{
		if(s == "#") break;
		string r = norm(s);
		in.push_back(s);
		if(!cnt.count(r)) cnt[r] = 0;
		cnt[r]++;
//		cout << "r = " << r << " " << cnt[r] <<"\n"; 
	}
	
	vector<string> out;
	
	for(int i = 0; i < in.size(); ++i)
	{
//		cout << cnt[norm(in[i])] << endl;
		if(cnt[norm(in[i])] == 1) 
			out.push_back(in[i]);
	}
		
		
	sort(out.begin(), out.end());
	for(int i = 0; i < out.size(); i++)
		cout << out[i] << "\n";
	return 0;
}

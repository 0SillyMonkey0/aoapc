#include <iostream>
#include <list>

using namespace std;

int main()
{
	string s;
	int mode = 1;
	while(getline(cin, s))
	{
		list<char> output;
		int len = s.size();
		list<char>::iterator it = output.begin();
		for(int i = 0; i < len; i++)
		{
			if(s[i] == ']')
				mode = 1;
			else if(s[i] == '[')
			{
				mode = 0;
				it = output.begin();
			}
			else if(mode)
				output.push_back(s[i]);
			else if(!mode)
				output.insert(it, s[i]);
		}
		for(list<char>::iterator it = output.begin(); it != output.end(); it++)
			printf("%c", *it);
		printf("\n");
	}
	return 0;
}

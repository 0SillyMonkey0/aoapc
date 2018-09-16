#include <iostream>

using namespace std;

struct act{
	int str, end;
};

int main()
{
	act s[11];
	for(int i  = 0; i < 11; i++)
		cin >> s[i].str >> s[i].end;
	
	int e = 0;
	for(int i = 0; i < 11; i++)
	{
		if(s[i].str >= e)
		{
			cout << s[i].str << " " << s[i].end << endl;
			e = s[i].end;
		}
	}
}

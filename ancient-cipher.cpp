#include <iostream>
#include <algorithm>

using namespace std;
const string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
	string a, b;
	while(cin >> a >> b)
	{
		int alp1[26] = {0}, alp2[26] = {0};
		int len = a.size();
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < alp.size(); j++)
			{
				if(a[i] == alp[j])
					alp1[j]++;
				if(b[i] == alp[j])
					alp2[j]++;
			}
		}
		sort(alp1, alp1 + 26);
		sort(alp2, alp2 + 26);
		int flag = 1;
		for(int i = 0; i < alp.size(); i++)
			if(alp1[i] != alp2[i])
				flag = 0;
				
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


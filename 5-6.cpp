#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 30000;
const float esp = 0.000001;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n; 
		cin >> n;
		int count = 0;
		vector<int>  point[maxn];
		map<int, int> y_axis;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if(!y_axis.count(y))
				y_axis[y] = count++;
			point[y_axis[y]].push_back(x);
		}
		float sys = 0;
		
		sort(point[0].begin(), point[0].end());
		sys = (float)(point[0][0] + point[0][point[0].size() - 1]) / 2;
//		cout << "DEBUG   " << sys << endl;
		int flag = 1;
		for(int i = 1; i < count; i++)
		{
			sort(point[i].begin(), point[i].end());
//			cout << "BEBUG   " << point[i][0] << "  " << point[i][point[i].size() - 1] << endl;
			if((abs((float)(point[i][0] + point[i][point[i].size() - 1]) / 2 - sys)) > esp)
			{
				flag = 0;
				break;
			}
		}
		
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}

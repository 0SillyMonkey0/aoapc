#include <iostream>
#include <queue>
#include <map>
#include <fstream> 
using namespace std;

int main()
{
	ofstream out("debug.txt");
	int T;
	cin >> T;
	while(T--)
	{
		int num, pos;
		cin >> num >> pos;
		queue<pair<int, int> > q;
		int time = 0;
		
		for(int i = 0; i < num; i++)
		{
			int prior;
			cin >> prior;
			q.push(make_pair(i, prior));
		}
		
		for(;;)
		{
			pair<int, int> p = q.front();
			q.pop();
			queue<pair<int ,int> > tmp = q;
			int flag = 1;
			while(tmp.size())
			{
				if(tmp.front().second > p.second)
				{
					flag = 0;
					break;
				}	 
				tmp.pop();
			}
			if(!flag)
				q.push(p);
			else
				time++;
			if(p.first == pos && flag)
				break;
				
		}
		cout << time << endl;
		out << time << endl;
	}
	return 0;
}

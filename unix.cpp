#include <iostream>
#include <string>
#include <algorithm>

#define maxcol 60
#define maxn 105

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		string file[maxn];
		int M = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> file[i];
			M = max(M, (int)file[i].size());
		}
//		cout << "M = " << M << endl;
		int col = (maxcol - M) / (M + 2) + 1;
		int row = (n - 1) / col + 1;
		sort(file, file + n);
		
		for(int i = 0; i < maxcol; i++)
			cout << "-";
		cout << endl;
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				string s = file[i + j * row];
				cout << s;
				if(j != col - 1)
					for(int k = 0; k < M + 2 - s.size(); k++)
						cout << " ";
				else
					for(int k = 0; k < M - s.size(); k++)
						cout << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}

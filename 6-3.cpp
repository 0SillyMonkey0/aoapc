#include <iostream>
#include <string>
#include <map>

using namespace std;

const int maxn = 1 << 27;

string fors, mids;

void build(int lf, int rf, int lm, int rm)
{
	int root;
	if(lf > rf || lm > rm)
		return;
	for(int i = lm; i <= rm; i++)
		if(fors[lf] == mids[i])
		{
			root = i;
			break;
		}
	int dis = root - lm;
	build(lf + 1, lf + dis,lm, root - 1);
	build(lf + dis + 1, rf, root + 1, rm);
	cout << mids[root];	
	return;
}

int main()
{
	
	while(cin >> fors >> mids)
	{			
		int count = 1;
		build(0, fors.size() - 1, 0, fors.size() - 1);
		cout << endl;
	}
} 

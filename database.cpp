#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxr = 10000 + 5;
const int maxc = 10 + 5;
int db[maxr][maxc] = { 0 };
map<string, int> IDcache;

int cnt = 0;
int ID(const string& s)
{
	if(!IDcache.count(s))
		IDcache[s] = ++cnt;
	return IDcache[s];
}
int m, n;
void find() {
  for(int c1 = 0; c1 < m; c1++)
    for(int c2 = c1+1; c2 < m; c2++) {
      map<pair<int, int>, int> d;
      for(int i = 0; i < n; i++) {
        pair<int, int> p = make_pair(db[i][c1], db[i][c2]);
        if(d.count(p)) {
          printf("NO\n");
          printf("%d %d\n", d[p]+1, i+1);
          printf("%d %d\n", c1+1, c2+1);
          return;
        }
        d[p] = i; //what
      }
    }
  printf("YES\n");
}


int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		IDcache.clear();
		char c = getchar();
		for(int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			int lastpos = -1;
			for(int j = 0; j < m; j++)
			{	
				int p = s.find(",", lastpos + 1);
//				cout <<"pos = " << p << endl;
				if(p == string::npos) p = s.length();
				db[i][j] = ID(s.substr(lastpos + 1, p - lastpos - 1));
//				cout << s.substr(lastpos + 1, p - lastpos - 1) << endl;
				lastpos = p;
			}
			
		}
		find();
	}
} 

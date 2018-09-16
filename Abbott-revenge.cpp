#include <iostream>
#include <queue> 
#include <cstring>
#include <vector>

using namespace std;

const string dirs = "NESW";
const string turns = "FLR";

int dir_id(char c)
{
	return dirs.find(c);
}

int turn_id(char c)
{
	return turns.find(c);
}

struct Node{
	int r, c, dir;
	Node(int r_ = 0, int c_ = 0, int dir_ = 0)
	{
		r = r_;
		c = c_;
		dir = dir_;
	}
};

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

Node walk(const Node& u, int turn)
{
	int dir = u.dir;
	if(turn == 1) dir = (dir + 3) % 4;
	if(turn == 2) dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

const int maxn = 10;
int has_edge[maxn][maxn][4][3], d[maxn][maxn][4];
Node p[maxn][maxn][4];
int r0, c0, r1, c1, r2, c2, dir;
bool inside(int r, int c)
{
	return (r >= 1 && r <= 9 && c >= 1 && c <= 9);
}

void print_ans(Node u)
{
	vector<Node> ans;
	for(;;)
	{
		ans.push_back(u);
		if(d[u.r][u.c][u.dir] == 0) break;
		u = p[u.r][u.c][u.dir];
	}
	ans.push_back(Node(r0, c0, dir));
	int cnt = 0;
    for(int i = ans.size()-1; i >= 0; i--)
	{
	    if(cnt % 10 == 0) printf(" ");
	    printf(" (%d,%d)", ans[i].r, ans[i].c);
	    if(++cnt % 10 == 0) printf("\n");
  	}
  	if(ans.size() % 10 != 0) printf("\n");
}

void solve()
{
	memset(d, -1, sizeof(d));
	d[r1][c1][dir] = 0;
	queue<Node> q;
	Node u(r1, c1, dir);
	q.push(u);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		if(u.r == r2 && u.c == c2)
		{
			print_ans(u);
			return;
		}
		for(int i = 0; i < 3; i++)
		{
			Node v = walk(u, i);
			
			if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0)
			{
				p[v.r][v.c][v.dir] = u;
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				q.push(v);
			}
		}
	}
	cout << "  No Solution Possible\n";
}

bool read_case() {
  char s[99], s2[99];
  if(scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6) return false;
  printf("%s\n", s);

  dir = dir_id(s2[0]);
  r1 = r0 + dr[dir];
  c1 = c0 + dc[dir];

  memset(has_edge, 0, sizeof(has_edge));
  for(;;) {
    int r, c;
    scanf("%d", &r);
    if(r == 0) break;
    scanf("%d", &c);
    while(scanf("%s", s) == 1 && s[0] != '*') {
      for(int i = 1; i < strlen(s); i++)
        has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
    }
  }
  return true;
}

int main()
{
	while(read_case()) {
    solve();
  }
  return 0;
}












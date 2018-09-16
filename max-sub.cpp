#include <iostream>
#include <algorithm> 

/* 4 -3 5 2 -1 2 6 -2        15 */ 
using namespace std;
const int maxn = 10000;
int max_sub(int* a, int n)
{
	int best = 0, s[n];
	s[0] = 0;
	for(int i = 1; i < n; i++)
		s[i] = s[i - 1] + a[i - 1];
		
	
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			best = max(s[j] - s[i], best);

	return best;
}

int max_sub(int *a, int x, int y)
{
	if(x == y)  return a[x];
	
	int m = (x + y) / 2;
	int best = max(max_sub(a, x, m), max_sub(a, m + 1, y));
	
	int L = a[m], R = a[m + 1];
	for(int i = m - 1, v = 0; i >= x; i--)
		L = max(L, v += a[i]);
		
	for(int i = m, v = 0; i <= y; i++)
		R = max(R, v += a[i]);
		
	return max(best, L + R);
}

int main()
{
	int a[] = {4, -3, 5, 2, -1, 2, 6, -2};
	int len = sizeof(a) / sizeof(a[0]);
	
	cout << max_sub(a, 0, len - 1);
	
	return 0;
}

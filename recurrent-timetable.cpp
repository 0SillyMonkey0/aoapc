#include <iostream>

using namespace std;

const int maxn = 100;
int A[maxn][maxn];

void arrange(int n)
{
	if(n == 1)
		return;
		
	int t = n / 2;
	arrange(t);
	for(int i = 0; i < t; i++)
		for(int j = 0; j < t; j++)
		{
			A[i + t][j] = A[i][j] + t;
			A[i][j + t] = A[i + t][j];
			A[i + t][j + t] = A[i][j];
		}
}

int main()
{
	int n, flag = 0;
	cin >> n;
	A[0][1] = 1;
	
	arrange(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
			
}

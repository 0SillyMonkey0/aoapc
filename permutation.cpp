#include <iostream>
#include <algorithm>
using namespace std;
void print_permutation(int *A, int n, int cur)
{ 
	if(cur == n)
	{
		for(int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << "\n";
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			int ok = 1;
			for(int j = 0; j < cur; j++)
				if(A[j] == i)
					ok = 0;
			
			if(ok)
			{
				A[cur] = i;
				print_permutation(A, n, cur + 1);
			}
		}
	}
} 
void print_permutation(int *A, int*P, int n, int cur, int* vis)
{
	if(cur == n)
	{
		for(int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << "\n";
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(!vis[i])
			{
				vis[i] = 1;
				A[cur] = P[i];
				print_permutation(A, n, cur + 1);
				vis[i] = 0;
			}
		}
	}
}
void print_permutation(int *A, int *P, int cur, int n)
{
	if(cur == n)
	{
		for(int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << "\n";
	}
	else
	for(int i = 0; i < n; i++)
	{
		if(!i || P[i] != P[i -1])
		{
			int c1 = 0, c2 = 0;
			for(int j = 0; j < cur; j++) if(A[j] == P[i]) c1++;
			for(int j = 0; j < n; j++) if(P[i] == P[j]) c2++;
			if(c1 < c2)
			{
				A[cur] = P[i];
				print_permutation(A, P, cur + 1,  n);
			}
		}
	}
}

int main()
{
	int A[100];
    int P[] = {1, 2, 3};
    int vis[100] = {0};
    
    print_permutation(A, P, 3,  0, vis);
    return 0;
}







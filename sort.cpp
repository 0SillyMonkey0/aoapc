#include <iostream>

using namespace std;

const int maxn = 1000;
void merge_sort(int *a, int x, int y, int *t)
{
	if(y > x)
	{
		int m = (x + y) / 2;
		merge_sort(a, x, m, t);
		merge_sort(a, m + 1, y, t);
		int count = x, pos1 = x, pos2 = m + 1;
		while(pos1 <= m && pos2 <= y)
		{
			if(a[pos1] < a[pos2])
				t[count++] = a[pos1++];
			else
				t[count++] = a[pos2++];
		}
		while(pos1 <= m) t[count++] = a[pos1++];
		while(pos2 <= y) t[count++] = a[pos2++];
		for(int i = x; i <= y; i++)  a[i] = t[i];
	}
}

void exchange(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void quick_sort(int *a, int x, int y)
{
	if(y > x)
	{
		int pivot = a[x];
		int i = x;
		for(int j = x + 1; j <= y; j++)
		{
			if(a[j] < pivot)
			{
				i++;
				exchange(a[i], a[j]);
			}
		}
		exchange(a[x], a[i]);
		
		quick_sort(a, x, i - 1);
		quick_sort(a, i + 1, y);
	}
}

int main()
{
	int a[] = {4, -3, 5, 2, -1, 2, 6, -2};
	int len = sizeof(a) / sizeof(a[0]);
	int t[maxn];
	quick_sort(a, 0, len - 1);
	for(int i = 0; i < len; i++)
		cout << a[i] << " ";
	return 0;
}

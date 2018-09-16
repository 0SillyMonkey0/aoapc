#include <iostream>  
using namespace std;  
  
bool b[20] = {0}; 
int a[20];
void print_subset(int n, bool* b, int cur)
{
	if(cur == n)
	{
		for(int i = 0; i < n; i++)
			if(b[i] == true)
				cout << a[i] << " ";
		cout << "\n";
		return;
	} 

	b[cur] = true;
	print_subset(n, b, cur + 1);
	b[cur] = false;
	print_subset(n, b, cur + 1);
}

void print_subset(int n, int s)
{
	for(int i = 0; i < n; i++)
		if(s & (1 << i)) cout << i << " ";
	cout << "\n";
}
  
int main() {  
    int n ;  
    cin >> n;
    for(int i = 0; i < (1 << n); i++)
    	print_subset(n, i);
}  

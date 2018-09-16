#include  <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int tri[3];
	for (int i = 0; i < 3; ++i)
		cin >> tri[i];
		
	sort(tri, tri + 3);
		
	if(tri[0] + tri[1] > tri[2])
		cout << "yes";
	else
		cout  << "not a triangle";
	
	return 0;
} 

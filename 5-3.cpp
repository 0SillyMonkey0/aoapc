#include <iostream>
#include <queue> 
using namespace std;

int main()
{
	for(;;)
	{
		int num;
		cin >> num;
		if(!num)
			break;
			
		queue<int> cards;
		for(int i = 1; i <= num; i++)
			cards.push(i);
			
		if(cards.size() > 1)
			cout << "Discarded cards: ";
		else
			cout << "Discarded cards:\n";
		while(cards.size() > 1)
		{
			cout << cards.front();
			if(cards.size() > 2)
				cout << ", ";
			else
				cout << "\n";
			cards.pop();
			int tmp = cards.front();
			cards.pop();
			cards.push(tmp);
		}
		cout << "Remaining card: " << cards.front() << "\n"; 
	}
	
	return 0;
}

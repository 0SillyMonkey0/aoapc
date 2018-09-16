#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BigInteger{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
private:
	vector<int> s;
	
public:
	BigInteger(long long num = 0){ *this = num; }
	BigInteger operator = (long long num)
	{
		s.clear();
		do
		{
			s.push_back(num % BASE);
			num /= BASE;
		} while(num > 0);
		return *this;
	}
	
	BigInteger operator = (const string& str)
	{
		s.clear();
		int x, len = (str.size() - 1) / WIDTH + 1;
		for(int i = 0; i < len; i++)
		{
			int end = str.length() - i*WIDTH;
			int start = max(0, end - WIDTH);
			x = stoi(str.substr(start, end - start));
			s.push_back(x);
		}
		return *this;
	}


	BigInteger operator + (const BigInteger& b) const
	{
		BigInteger c;
		c.s.clear();
		for(int i = 0, g = 0; ;i++)
		{
			if(g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if(i < s.size()) x += s[i];
			if(i < b.s.size()) x += b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c;
	}
	
	friend ostream& operator << (ostream &out, const BigInteger& x)
	{
		for(int i = x.s.size() - 1; i >= 0; i--)
			cout << x.s[i];
		return out;
	}
	
	friend istream& operator >> (istream &in, BigInteger& x)
	{
		string s;
		if(!(in >> s)) return in;
		x = s;
		return in;
	} 
};



int main()
{
	BigInteger a, b, c;
	b = 234;
    cin >> a;
    
    cout << b+a;
	return 0;
}

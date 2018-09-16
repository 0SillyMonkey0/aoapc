#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

struct book{
	string title;
	string author;
	bool is_on_shelf;
	bool is_returned;
};

typedef struct book book;

void split(const string& s, vector<book> &books)
{
	string::const_iterator it = s.begin() + 1;
	while(*it != '"') it++;
	book b;
	b.title = string(s.begin(), it + 1);
	b.author = string(it + 5, s.end());
	b.is_on_shelf = true;
	b.is_returned  = true;
	books.push_back(b);	
}

void split_ins(const string& s, string& ins, string& b)
{
	if(s.size() == 6)
		ins = "SHELVE";
	else
	{
		string::const_iterator it = s.begin();
		while(*it != '"') it++;
		ins = s.substr(0, 6);
		b = string(it, s.end());	
	}
	
	
}
bool cmp(const book &a, const book &b)
{
	if(a.author < b.author)
		return true;
	else if(a.author > b.author)
		return false;
	else
		return a.title < b. title;
}

int find_prior(const vector<book>& books, int ind)
{
	ind -= 1;
	for(; ind >= 0; ind--)
	{
		if(books[ind].is_on_shelf == true)
			return ind;
	}
	return -1;
}

int main()
{
//	ofstream out("debug.txt");
	string s;
	vector<book> books;
	for(;;)
	{
		getline(cin, s);
		if(s == "END")
			break;
		
		split(s, books);
	}
	sort(books.begin(), books.end(), cmp);
	
	map<string, int> id;
	for(int i = 0; i < books.size(); i++)
		id[books[i].title] = i;
		
	vector<book> returned;
	for(;;)
	{
		string ins, b;
		getline(cin, s);
		if(s == "END")
			break;
		split_ins(s, ins, b);
		
		if(ins[0] == 'B')
		{
			books[id[b]].is_returned = false;
			books[id[b]].is_on_shelf = false;
		}
			
			
		else if(ins[0] == 'R')
		{
			books[id[b]].is_returned = true;
			returned.push_back(books[id[b]]);
		}
		else
		{
			sort(returned.begin(), returned.end(), cmp);
			
			for(int i = 0; i < returned.size(); i++)
			{
				int ind = id[returned[i].title];
//				cout << "DEBUG----------------ind   " << ind << endl; 
				int prior = find_prior(books, ind);
//				cout << "DEBUG----------------prior   " << prior << endl; 
				if(prior >= 0)
					cout << "Put " << returned[i].title << " after " << books[prior].title << endl;
				else
					cout << "Put " << returned[i].title << " first\n";
					
//				if(prior >= 0)
//					out << "Put " << returned[i].title << " after " << books[prior].title << endl;
//				else
//					out << "Put " << returned[i].title << " first\n";
				 books[ind].is_on_shelf = true;
			}
			returned.clear();
			cout << "END\n";
//			out << "END\n";
		}
	
	}
	return 0;
}

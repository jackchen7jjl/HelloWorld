#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum
{
	NUM = 5
};

vector<string> books(NUM);

string operator+(string str, int i);

int main()
{
	cout << "books" << endl;

	for (int i = 0; i < NUM; i++)
	{
		string bookName = "book " + i;
		//cin.getline(bookName);
		//books.push_back(bookName);
		books[i] = bookName;
	}

	for (int i = 0; i < NUM; i++)
	{
		cout << books[i] << endl;
	}

	cin.get();
	cin.get();
	return 0;
}

string operator+(string str, int i)
{
	str = str + "0";
	return str;
}
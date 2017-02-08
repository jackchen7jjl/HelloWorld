#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main3()
{
	string fileName = "files/test.txt";
	ifstream fin;
	fin.open(fileName);
	if (fin.is_open() == false)
	{
		cerr << "Can't open file. Bye" << endl;
		cin.get();
		cin.get();
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << ", " << item.size() << endl;
		getline(fin, item, ':');
	}
	cout << "Done" << endl;
	fin.close();
	cin.get();
	cin.get();
	return EXIT_SUCCESS;
}
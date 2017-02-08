#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main3()
{
	//string fileName;
	//cout << "Enter name for new file: ";
	//cin >> fileName;

	//ofstream fout{ fileName.c_str()};
	//fout << "For your eyes only!" << endl;
	//cout << "Enter your secret number: ";
	//float secret;
	//cin >> secret;

	//fout << "your secret number is " << secret << endl;
	//fout.close();

	//ifstream fin(fileName.c_str());
	//cout << "Here are the contents of " << fileName << ": " << endl;
	//char ch;
	//while (fin.get(ch))
	//{
	//	cout << ch;
	//}
	//cout << "Done" << endl;
	//fin.close();


	//ofstream fout;
	//fout.open("F:\\cworkspace\\ToolKit\\gitUpdater\\repositories0.xml");
	//string str = "hello fout!";
	//fout << str << endl;
	//fout << 123 << endl;
	//fout.flush();
	//fout.close();

	ifstream fin;
	char ch;
	fin.open("F:\\cworkspace\\ToolKit\\gitUpdater\\repositories.xml");
	cout << fin.is_open() << endl;
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();

	cout << endl;

	cin.get();
	cin.get();
	return 0;
}
#include <iostream>
#include "coordin.h"

using namespace std;

int global = 1000;
static int one_file = 50;

void func1();
void func2(int q);

int main()
{
	rect rplace;
	polar pplace;

	func1();
	func1();

	cout << "Enter the x and y values:" << endl;
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit : )";
	}



	cout << "Bye!\n";

	cin.get();
	cin.get();

	return 0;
}

void func1()
{
	static int count = 0;
	cout << "count = " << count << endl;
	count++;
}

void func2(int q)
{

}
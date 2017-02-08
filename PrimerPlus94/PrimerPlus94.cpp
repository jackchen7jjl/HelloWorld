#include <iostream>
using namespace std;


void oil(int x);

int main()
{
	int texas = 31;
	int year = 2011;

	cout << "In main, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "In main, year = " << year << ", &year = " << &year << endl;

	oil(texas);

	cout << "In main, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "In main, year = " << year << ", &year = " << &year << endl;

	cin.get();
	cin.get();
	return 0;
}

void oil(int x)
{
	int texas = 5;
	cout << "In oil, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "In oil, x = " << x << ", &x = " << &x << endl;

	{
		int texas = 116;
		cout << "In oil block, texas = " << texas << ", &texas = " << &texas << endl;
		cout << "In oil block, x = " << x << ", &x = " << &x << endl;
	}

	cout << "In oil post block, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "In oil post block, x = " << x << ", &x = " << &x << endl;
}
#include <iostream>
#include <exception>
using namespace std;

int main2()
{
	cin.exceptions(ios_base::failbit);
	cout << "Enter numbers: ";
	int sum = 0;
	int item;
	try
	{
		while (cin >> item)
		{
			sum += item;
		}
	}
	catch (ios_base::failure & bf)
	{
		cout << bf.what() << endl;
		cout << "o! the horror!\n";
	}
	

	cout << "last value entered = " << item << endl;
	cout << "sum = " << sum << endl;
	cin.clear();

	cin.get();
	cin.get();
	cin.get();
	return 0;
}
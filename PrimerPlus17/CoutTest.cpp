#include <iostream>
using namespace std;

int main1()
{
	char *str = "hello cout!";
	int a = 10;
	cout << a << endl;
	cout << &a << endl;
	cout << str << endl;
	cout << *str << endl;
	cout << (void *)str << endl;

	cout.put('W');

	cout << 'W' << endl;

	char *str2 = "hello ÖÐÎÄ!";
	cout << strlen(str2) << endl;

	cout.write(str2,15) << endl;

	long long1 = 123;
	cout.write((char *)&long1, sizeof(long)) << endl;

	float f0 = 123 + 1.0/9.0;
	cout.precision(5);
	cout << f0 << "end" << endl;

	cout << hex;

	cout.width(10);
	cout << long1 << endl;

	char *name = new char();
	int int1;
	char char2;

	//cin >> name >> int1 >> char2;
	//cout << name << endl;
	//cout << int1 << endl;
	//cout << char2 << endl;

	int sum = 0;
	int item;
	while (cin >> item)
	{
		sum += item;
	}
	cin.clear();
	
	cout << "sum = " << sum << endl;

	cin.get();
	cin.get();
	return 0;
}
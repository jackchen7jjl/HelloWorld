#include <iostream>
using namespace std;

struct inflatable
{
	char name[20];
	float volumn;
	double price;
};

int main()
{
	double a = 0.1;
	double b = 0.5;

	cout << "a value = " << a << endl;
	cout << "and a address = " << &a << endl;
	cout << "b value = " << b << endl;
	cout << "and b address = " << &b << endl;

	int updates = 6;
	int * p_updates;
	p_updates = &updates;

	cout << "value updates = " << updates << endl;
	cout << "*p_updates = " << *p_updates << endl;

	cout << "address &updates = " << &updates << endl;
	cout << "p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "value updates=" << updates << endl;


	double *p3 = new double[3];
	p3[0] = 0.1;
	p3[1] = 0.2;
	p3[2] = 0.3;

	cout << "p3[1] = " << p3[1] << endl;
	p3 = p3 + 1;

	cout << "now p3[0] is " << p3[0] << endl;
	p3 = p3 - 1;
	delete[] p3;


	inflatable *ps = new inflatable;
	cout << "enter name please : " << endl;
	cin.get(ps->name, 20);
	cout << "enter price :" << endl;
	cin >> (*ps).price;
	cout << ps->name << ps->price;

	cin.get();
	cin.get();
	return 0;
}
  
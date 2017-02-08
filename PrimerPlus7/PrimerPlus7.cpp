#include <iostream>
#include <cmath>
using namespace std;

void simple();
void swapr(int &a,int &b);
void swapp(int *p,int *q);
void swapv(int a, int b);


int main()
{
	cout << "Hey ";
	simple();
	cout << ",how are you?";

	int a = 102;
	int b = 103;

	swapr(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	swapp(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	swapv(a,b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cin.get();
	cin.get();
	return 0;
}

void simple()
{
	cout << "Jack " << sqrt(25);
}

void swapr(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapp(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T *a, T *b, int n);

void show(int a[]);

int main()
{
	int a = 101;
	int b = 102;

	cout << "a = " << a << endl;
	cout << "b =" << b << endl;

	Swap(a, b);

	cout << "a = " << a << endl;
	cout << "b =" << b << endl;

	double c = 1.02;
	double d = 2.35;

	Swap(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	int d1[4] = {1,3,5,7};
	int d2[5] = {2,4,6,8};
	show(d1);

	Swap(d1,d2,4);
	show(d1);

	cin.get();
	cin.get();
	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
 }

template <typename T>
void Swap(T *a, T *b, int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void show(int a[])
{
	for (int i = 0; i < 4; i++)
	{
		cout << "a" << i << " = " << a[i] << endl;
	}
}



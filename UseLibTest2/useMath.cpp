#include "StaticMath.h"
#include <iostream>
using namespace std;

int main2()
{
	double a;
	double b;

	cout << "Enter a : " << endl;
	cin >> a;

	cout << "Enter b: " << endl;
	cin >> b;

	cout << "a = " << a << " and b= " << b << endl;

	cout << "a + b = " << StaticMath::add(a, b) << endl;

	StaticMath sm;
	sm.print();

	cin.get();
	cin.get();
	return 0;
}
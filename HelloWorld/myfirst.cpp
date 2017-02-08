#include <iostream>
#include <cmath>
using namespace std;
double mysqrt(double value);

int main()
{
	double area;
	cout << "please input the area" << endl;
	cin >> area;
	cout << "The side is " << mysqrt(area) << endl;
	cin.get();
	cin.get();
	return 0;


	//int age;
	//cout << "how old are you?" << endl;
	//cin >> age;
	//cout << "You are " << age << " years old!";
	//cin.get();
	//cin.get();
	//return 0;
}

double mysqrt(double value)
{
	cout << "ha ha!" << endl;
	return sqrt(value);
}
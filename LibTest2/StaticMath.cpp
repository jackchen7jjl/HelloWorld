#include "StaticMath.h"
#include <iostream>
using namespace std;

StaticMath::StaticMath()
{

}

StaticMath::~StaticMath()
{

}

double StaticMath::add(double a, double b)
{
	return a + b;
}

double StaticMath::sub(double a, double b)
{
	return a - b;
}

double StaticMath::mul(double a, double b)
{
	return a * b;
}

double StaticMath::div(double a, double b)
{
	return a / b;
}

void StaticMath::print()
{
	cout << "static Math " << endl;
}

int main()
{
	double a = 12;
	double b = 6;
	cout << "main in Lib: " << StaticMath::mul(a, b) << endl;
	cin.get();
	cin.get();
	return 0;
}


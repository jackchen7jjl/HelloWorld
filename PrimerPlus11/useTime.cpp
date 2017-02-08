#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	Time t(2,30);
	t.show();

	Time t2 = Time(3, 50);
	t2.show();

	Time t3 = t + t2;
	t3.show();

	Time t4 = 3 * t2;
	t4.show();

	cin.get();
	cin.get();
}
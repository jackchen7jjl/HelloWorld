#include <iostream>
#include "Stock00.h"

using namespace std;

int main()
{
	Stock sto1 = Stock("MSS", 20, 12.5);
	sto1.show();

	Stock sto2 = Stock("mokylin", 20, 15.5);
	sto2.show();

	const Stock &top = sto1.topVal(sto2);
	top.show();
	cout << &sto2 << "," << &top << endl;

	/*sto1.buy(15, 18.25);
	sto1.show();

	sto1.sell(10, 20);
	sto1.show();

	{
		Stock sto2;
		sto2.show();
	}*/


	Stock stos[4];
	
	for (int i = 0; i < 4; i++)
	{
		cout << &stos[i] << endl;
	}

	cin.get();
	cin.get();

	return 0;
}
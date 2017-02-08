#include <iostream>

using namespace std;

int main()
{
	//int totalNumbers = 5;
	//double totalValue = 0;
	//double enterNumber;
	//for (int i = 0; i < totalNumbers; i++)
	//{
	//	cout << "Enter number " << i << " please :" << endl;
	//	cin >> enterNumber;
	//	totalValue += enterNumber;
	//}
	//cout << "total : " << totalValue << endl;


	char ch;
	int count = 0;
	cout << "Enter characters , enter # to quit: " << endl;
	cin.get(ch);
	while (cin.fail() == false)
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read";

	cin.get();
	cin.get();
	return 0;
}
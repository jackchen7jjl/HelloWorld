#include <iostream>
#include <new>

const int BUF = 5120;
const int N = 5;

char buffer[BUF];

int main()
{
	using namespace std;

	double *pd1, *pd2;
	int i;

	cout << "Calling new and placement new:\n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];

	for (i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}

	cout << "Memory addresses:\n" << " heap: " << pd1 << " static: " << (void *)buffer << endl;

	cout << "Memory contents:\n";

	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	cout << "\nCalling new and placement new second time:\n";
	double *pd3, *pd4;

	pd3 = new double[N];
	pd4 = new (buffer) double[N];

	for (i = 0; i < N; i++)
	{
		pd3[i] = pd4[i] = 1000 + 40.0 * i;
	}

	cout << "Memory contents:\n";

	for (i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << "\nCalling new and placement new third time:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];

	for (i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	}


	cout << "Memory contents:\n";

	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;

	cin.get();
	cin.get();
	return 0;
}
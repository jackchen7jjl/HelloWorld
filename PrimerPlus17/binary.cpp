#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

inline void eatline() { while (cin.get() != '\n') continue; }

struct planet
{
	char name[20];
	double population;
	double g;
};

const char *fileName = "planets.dat";

int main()
{
	planet pl;
	cout << fixed << right;

	ifstream fin;
	fin.open(fileName, ios_base::in | ios_base::binary);

	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << fileName << endl;
		while(fin.read((char *) &pl,sizeof(pl)))
		{
			cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}

	ofstream fout(fileName, ios::out | ios::app | ios::binary);

	if (!fout.is_open())
	{
		cerr << "Cann't open " << fileName << " file for output" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names (enter a blank line to quit)" << endl;

	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "Enter population : ";
		cin >> pl.population;
		cout << "Enter g: ";
		cin >> pl.g;
		eatline();
		fout.write((char*)&pl, sizeof(pl));
		cout << "Enter guest names (enter a blank line to quit)" << endl;
		cin.get(pl.name, 20);
	}

	fout.close();

	fin.open(fileName, ios_base::in | ios_base::binary);

	if (fin.is_open())
	{
		cout << "Here are the new contents of the " << fileName << endl;
		while (fin.read((char *)&pl, sizeof(pl)))
		{
			cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}

	cin.clear();
	cout << "Done" << endl;
	cin.get();
	cin.get();
	return 0;
}

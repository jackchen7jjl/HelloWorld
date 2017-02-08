#include <iostream>
#include "Stock00.h"

Stock::Stock()
{
	company = "apple";
	shares = 100;
	share_val = 1.56;
	set_tot();
}

Stock::Stock(const std::string &co, long n, double pr)
{
	company = co;
	shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	std::cout << "bye company " << company << std::endl;
}

void Stock::acquire(const std::string &co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares cann't be negative; " << company << " shares set to 0.\n";
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	shares += num;
	share_val = price;
	set_tot();
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num > shares)
	{
		cout << "not enought shareds!" << std::endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	std::cout << "Company: " << company
		<< " shares: " << shares
		<< " Share Price: $" << share_val
		<< " total worth: $" << total_val << std::endl;
}

const Stock & Stock::topVal(const Stock &stCompar) const
{
	if (stCompar.total_val > total_val)
		return stCompar;
	return *this;
}

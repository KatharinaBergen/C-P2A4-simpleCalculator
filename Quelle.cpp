/*
Author: Kat Bergen
v.01 19.05.2020
source folder: C:\Users\katha\source\repos\

simple calculator including output of sorted numbers

pad1-P2-A4
*/


#include <iostream>
using std::cout;
using std::cin;

#include <vector>
#include <algorithm>


//function to calculate sum of 3 variables 
int calculateSum(const int i1, const int i2, const int i3)
{
	return i1 + i2 + i3;
}


//function to calculate product of 3 variables 
int calculateProduct(const int i1, const int i2, const int i3)
{
	return i1 * i2 * i3;
}


//function to calculate difference of 2 variables 
int calculateDifference(const int i1, const int i2)
{
	if (i1 >= i2)
		return i1 - i2;
	else
		return i2 - i1;
}

//function to calculate quotient of 2 variables 
double calculateQuotient(const int i1, const int i2)
{
	if(i2 == 0) throw std::runtime_error{ "zero devision error" };
	return (i1 * 1.0) / (i2 * 1.0);
}


int main() try
{
	int ix{ -1 };
	int iy{ -1 };
	int iz{ -1 };
	std::vector<int> vInts{};

	//Input 3 numbers between 0 and 999

	while (ix < 0 || ix > 999)
	{
		cout << "Bitte geben Sie eine Zahl zwischen 0 und 999 ein.\n";
		cin >> ix;
		if (!cin) throw std::runtime_error{ "data type error" };
	}

	vInts.push_back(ix);

	while (iy < 0 || iy > 999)
	{
		cout << "Bitte geben Sie eine weitere Zahl zwischen 0 und 999 ein.\n";
		cin >> iy;
		if (!cin) throw std::runtime_error{ "data type error" };
	}

	vInts.push_back(iy);

	while (iz < 0 || iz > 999)
	{
		cout << "Bitte geben Sie eine weitere Zahl zwischen 0 und 999 ein.\n";
		cin >> iz;
		if (!cin) throw std::runtime_error{ "data type error" };
	}

	vInts.push_back(iz);
	std::sort(vInts.begin(), vInts.end());

	//output

	cout << "\nSie haben diese Zahlen einetippt, hier sortiert nach größe: ";
	for (unsigned int i{ 0 }; i < vInts.size(); i++)
	{
		cout << vInts.at(i) << ',';
	}

	cout << "\n\nSum of " << ix << '+' << iy << '+' << iz << " : " << calculateSum(ix, iy, iz);
	cout << "\nProduct of " << ix << '*' << iy << '*' << iz << " : " << calculateProduct(ix, iy, iz);

	cout << "\n\nSum of " << ix << '+' << iy << '+' << iz << " : " << calculateSum(ix, iy, iz);
	cout << "\nProduct of " << ix << '*' << iy << '*' << iz << " : " << calculateProduct(ix, iy, iz);

	cout << "\n\nDifference of " << ix << '-' << iy << " : " << calculateDifference(ix, iy);
	cout << "\nDifference of " << iy << '-' << iz << " : " << calculateDifference(iy, iz);

	cout << "\n\nQuuotient of " << ix << '/' << iy << " : " << calculateQuotient(ix, iy);
	cout << "\nQuuotient of " << iy << '/' << iz << " : " << calculateQuotient(iy, iz);

	return 0;
}
catch (std::exception& e)
{
	std::cerr << std::endl << std::endl << e.what() << std::endl << std::endl ;
	return -1;
}

catch (...)
{
	std::cerr << "Other error";
	return -1;
}
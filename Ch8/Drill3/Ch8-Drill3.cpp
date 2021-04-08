// Ch8-Drill3.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "std_lib_facilities.h"

namespace X
{
	int var = 0;
	void print()
	{
		cout << "Namespace X - Var: " << var << endl;
	}
}

namespace Y
{
	int var = 0;
	void print()
	{
		cout << "Namespace Y - Var: " << var << endl;
	}
}

namespace Z
{
	int var = 0;
	void print()
	{
		cout << "Namespace Z - Var: " << var << endl;
	}
}

int main()
{
	X::var = 7;
	X::print();

	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}

	print();
	X::print();

	keep_window_open();

	return 0;
}
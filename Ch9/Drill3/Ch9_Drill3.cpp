// Ch9_Drill3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//9.4.3

#include "std_lib_facilities.h"
class Date 
{
public:
	Date(int y, int m, int d);

	void add_day(int n);

	int month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

private: 
	int y, m, d;
};

Date::Date(int yy, int mm, int dd)
{
	int yearMin(1900), yearMax(2200);
	if (yy > yearMax || yy < yearMin)
		cout << "Invalid year!";
	if (mm > 12 || mm < 1)
		cout << "Invalid month!";
	if (dd > 31 || dd < 1)
		cout << "Invalid day!" << endl;
	else
	{
		y = yy; m = mm; d = dd;
	}
}

void Date::add_day(int n) //wrapping days after 31
{
	if (d += n > 31)
	{
		d = 1;
		++m;
	}
}


ostream& operator<<(ostream& os, const Date& d)
{
	return os << "(" << d.year()
		<< "," << d.month()
		<< "," << d.day() << ")";
}

int main()
{
	Date today(1978, 6, 31);
	Date tomorrow(today);

	tomorrow.add_day(1);

	cout << today << endl;
	cout << tomorrow << endl;

	Date invalidDate{ 1500,12,-1 };

	keep_window_open();
	return 0;
}

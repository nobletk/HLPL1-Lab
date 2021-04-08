// Ch9_Drill2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//9.4.2

#include "std_lib_facilities.h"
struct Date
{
	Date(int y, int m, int d);
	void add_day(int n);
	int y, m, d;
};

Date::Date(int yy,int mm,int dd)
{
	int yearMin(1900), yearMax(2200);
	if(yy<yearMin||yy>yearMax)
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

void Date::add_day(int n)
{
	if (d += n > 31) //wrapping day after 31
	{
		d = 1;
		++m;
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << "(" << d.y
		<< "," << d.m
		<< "," << d.d << ")";
}

int main()
{
	Date today(1978, 6, 31);
	Date tomorrow(today);

	tomorrow.add_day(1);

	cout << today << endl;
	cout << tomorrow << endl;

	Date invalidDate{ 1800,20,-1 };

	keep_window_open();
	return 0;
}
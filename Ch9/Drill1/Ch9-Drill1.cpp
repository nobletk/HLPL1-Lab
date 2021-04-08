// Ch9-Drill1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//9.4.1

#include "std_lib_facilities.h"
struct Date {
	Date(int y, int m, int d);

	int y;
	int m;
	int d;
};

Date::Date(int yy, int mm, int dd)
{
	int yearMin(1900), yearMax(2200);
	if (yy<yearMin || yy>yearMax)
		cout << "Invalid year!";
	if (mm > 12 || mm < 1)
		cout << "Invalid month!";
	if (dd < 1 || dd>31)
		cout << "Invalid day!";
	else
	{
		y = yy; m = mm; d = dd;
	}
}

void add_day(Date& dd, int n) //increase dd by n days
{
	dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << "(" << d.y
		<< "," << d.m
		<< "," << d.d << ")";
}

int main()
{
	Date today(1978, 6, 25);
	Date tomorrow(today);

	add_day(tomorrow, 1);

	cout << today << endl;
	cout << tomorrow << endl;

	Date invalidDate{ 1000,20,-1 }; //invalid date

	keep_window_open();
	return 0;
}
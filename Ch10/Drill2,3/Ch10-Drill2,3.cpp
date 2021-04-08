// Ch10-Drill2,3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//prompt the user to input seven (x,y) pairs. As the data is entered
//store it in a vector of Points called original_points.


#include "std_lib_facilities.h"

struct Point
{
	double x, y;
};

double getNumber()
{
	double d;
	while (!(cin >> d))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input!";
	}
	return d;
}

void getPoints(int loop,vector<Point>& points)
{
	Point p;
	for(int i=0;i<loop;i++)
	{   cout << "Please enter" << loop << "pair(s) of points. " << endl;
	    cout << "Points" << i + 1 << endl;
		cout << "X:"; p.x = getNumber();
		cout << "Y:"; p.y = getNumber();
		points.push_back(p);

	}

}
int main()
{
	vector<Point> v_originalPoints;
	getPoints(7, v_originalPoints);

	cout << "......" << endl; //Drill 3
	for (uint32_t i = 0; i < v_originalPoints.size(); i++)
		cout << v_originalPoints[i].x << "," << v_originalPoints[i].y << endl;

	char ch;
	cin >> ch;
	return 0;
	 
}

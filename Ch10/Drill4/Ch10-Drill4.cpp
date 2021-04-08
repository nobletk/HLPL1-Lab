// Ch10-Drill4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Open an ofstream and output each point to a file named mydata.txt

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

void getPoints(int loop, vector<Point>& points)
{
	Point p;
	for (int i = 0; i < loop; i++)
	{
		cout << "Please enter" << loop << "Pair(s) of points." << endl;
		cout << "Points" << i + 1 << endl;
		cout << "X:"; p.x = getNumber();
		cout << "Y:"; p.y = getNumber();
		points.push_back(p);

	}
}

void outputPointsToFile(string filename, const vector<Point>& points)
{
	if (ofstream outFile{ filename })
		for(Point p:points)
		    outFile << '(' << p.x<< ','<<p.y << ")\n";
	else
		cout << "Error,can't open output file:" << filename << endl;

}

int main()
{
	vector<Point> v_originalPoints;
	getPoints(7, v_originalPoints);
	outputPointsToFile("mydata.txt", v_originalPoints);

	cout << "........................" << endl;
	for (uint32_t i = 0; i < v_originalPoints.size(); ++i)
		cout << v_originalPoints[i].x << "," << v_originalPoints[i].y << endl;

	keep_window_open();
	return 0;
}
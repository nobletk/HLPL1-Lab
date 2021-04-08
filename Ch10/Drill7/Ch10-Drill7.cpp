// Ch10-Drill7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Compare the two vectors and print "Something's wrong!" if the number of 
//elements or the values of elements differ.

#include "std_lib_facilities.h"

struct Point
{
	double x, y;
};

double getNumber()
{
	double d;
	//clears up cin if NaN was entered, taken from http://www.cplusplus.com/forum/beginner/21595/
	while (!(cin >> d))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	return d;
}


void getPoints(int loop, vector<Point>& points)
{
	Point p;
	for (int i = 0; i < loop; ++i)
	{
		cout << "Please enter " << loop << " pair(s) of points." << endl;
		cout << "Points " << i + 1 << endl;
		cout << "X: "; p.x = getNumber();
		cout << "Y: "; p.y = getNumber();
		points.push_back(p);
		
	}
}

void outputPointsToFile(string filename, const vector<Point>& points)
{
	if (ofstream outFile{ filename })
		for (Point p : points)
			outFile << '(' << p.x << ',' << p.y << ")\n";
	else
		cout << "Error, can't open output file " << filename << endl;
}

void inputPointsToFile(string filename, vector<Point>& points)
{
	string line, num1, num2;
	Point p;
	if (ifstream inFile{ filename })
	{
		while (getline(inFile, line))
		{
			//find where the comma is
			size_t found = line.find_first_of(",");

			//get first number (from after '(' until ',' )
			num1 = line.substr(1, found - 1);
			//get second number (from after ',' until ')' )
			num2 = line.substr(found + 1, line.size() - 2);

			p.x = stod(num1); p.y = stod(num2);
			points.push_back(p);
		}
	}
	else
		cout << "Error, can't open input file " << filename << endl;
}


bool compareVectors(const vector<Point>& p1, const vector<Point>& p2)
{
	if (p1.size() != p2.size())
		return false;
	else
	{
		for (uint32_t i = 0; i < p1.size(); ++i)
		{
			if (p1[i].x != p2[i].x ||
				p1[i].y != p2[i].y)
				return false;
		}
	}

	return true;
}


int main()
{
	vector<Point> v_originalPoints;
	vector<Point> v_processedPoints;
	getPoints(2, v_originalPoints);
	outputPointsToFile("mydata.txt", v_originalPoints);
	inputPointsToFile("mydata.txt", v_processedPoints);


	cout << "[original Points]----------------------------------------" << endl;
	for (uint32_t i = 0; i < v_originalPoints.size(); ++i)
		cout << v_originalPoints[i].x << ", " << v_originalPoints[i].y << endl;

	cout << "[processed Points]----------------------------------------" << endl;
	for (uint32_t i = 0; i < v_processedPoints.size(); ++i)
		cout << v_processedPoints[i].x << ", " << v_processedPoints[i].y << endl;

	if (!compareVectors(v_originalPoints, v_processedPoints))
		cout << "Something's wrong!" << endl;

	keep_window_open();
	return 0;
}
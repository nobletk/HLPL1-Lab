// Ch17-p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

void printArray(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << a[i] << endl;
}
int main()
{
	//drill 1-Allocate an int, intialise it to 7, and assign its address to a variable p1.
	int n = 7;
	int* p1 = &n;

	//drill 2-Print out the value of p1 and of the int it points to.
	cout << "n:" << n <<endl<< "p1:" << p1 << endl;

	//drill 3-Allocate an array of seven ints ; initialise it to 1, 2, 3, 4, 8, etc.; and 
	//assign its address to a variable p2.
	int sevenInts[7] = { 1,2,4,8,16,32,64 };
	int* p2 = sevenInts;

	//drill 4-Print out the value of p2 and of the array it points to.
	cout << "---------------------------" << endl;
	printArray(cout, p2, 7);
	cout << "p2:" << p2 << endl;

	//drill 5 - Declare an int* called p3 and initialise it with p2.
	int* p3 = p2;

	//drill 6
	p2 = p1;

	//drill 7
	p2 = p3;

	//drill 8-Print out the values of p1 and p2 and of what they point to
	cout << "---------------------------" << endl;
	cout << "p1:" << p1 <<"/"<<*p1<< endl;
	printArray(cout, p2, 7);

	//drill 9-nothing is allocated on the free store but on the stack

	//drill 10-Allocate an array of ten ints; intialise it to 1, 2, 4, 8, etc.; and assign 
	//its address to a variable p1
	int tenInts[10] = { 1,2,4,8,16,32,64,128,256,512 };
	p1 = tenInts;

	//drill 11-Allocate an array of ten ints, and assign its address to a variable p2
	int tenInts2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	p2 = tenInts2;

	//drill 12-Copy the values from the array pointed to by p1 into the array pointed to by p2.
	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	//drill 13-Repeat 10-12 using a vector rather than an array.
	vector<int> v_tenInts{ 1,2,4,8,16,32,64,128,256,512 };
	p1 = &v_tenInts[0];
	vector<int>v_tenInts2{ 1,2,3,4,5,6,7,8,9,10 };
	p2 = &v_tenInts2[0];
	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	return 0;
	}
   


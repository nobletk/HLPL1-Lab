// Ch17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

void printArray10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
		os << a[i] <<endl;

}

void printArray(ostream& os, int* a, int n) //drill 7
{
	for (int i = 0; i < n; ++i)
		os << a[i] << endl;
}
int* allocateArray(int n)
{
	int* a = new int[n];
	int counter = 100;
	for (int i = 0; i < n; ++i)
		a[i] = counter++;
	return a;
}
//drill 10
vector<int*> allocateVector(int n)
{
	vector<int*>temp;
	int counter = 100;
	for (int i = 0; i < n; ++i)
		temp.push_back(new int{ counter++ });
	return temp;
}

void printVector(vector<int*>v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << *v[i] << endl;
}
void deleteVector(vector<int*>v)
{
	for (int i = 0; i < v.size(); ++i)
		delete v[i];
}

int main()
{
	int* tenInts = new int[10]; //drill 1
	
	//drill 2 print out tenInts
	for (int i = 0; i < 10; ++i)
		cout << tenInts[i] ;
	cout << endl;
	
	//drill 3
	//delete[] tenInts; 

	//drill 4 Write a function print_array10(ostream& os, int* a) that prints out the 
	//values of a(assumed to have ten elements) to os.
	cout << "---------------------------------" << endl;
	printArray10(cout, tenInts);
	delete[]tenInts;

	//drill 5 -Allocate an array of ten ints on the free store; initialise it with the 
	//values 100, 101, 102, etc.;and print out its values.
	int* tenInts2 = new int[10]{ 100,101,102,103,104,105,106,107,108,109};
	cout << "---------------------------------\n" << "\n10Int2 array:\n" << endl;
	printArray10(cout, tenInts2);
	delete[] tenInts2;

	//drill 6-Allocate an array of 11 ints on the free store; initialise it with the 
	//values 100, 101, 102, etc.;and print out its values.
	int* intArray = new int[11]{ 100,101,102,103,104,105,106,107,108,109,110 };
	cout << "---------------------------------\n" << "\n11Int array:\n" << endl;
	printArray(cout, intArray,11);
	delete[] intArray;

	//drill 8-Allocate an array of 20 ints on the free store; initialise it with the 
	//values 100, 101, 102, etc.;and print out it's values.
	int* twentyInts = allocateArray(20);
	cout << "---------------------------------\n" << "\n20Int array:\n" << endl;
	printArray(cout, twentyInts, 20);
	delete[] twentyInts;

	//drill 10-Do 5, 6, and 8 using a vector instead of an arrayand a  print_vector()
		//instead of print_array().
	vector<int*>v_tenInts = allocateVector(10);
	cout << "---------------------------------\n" << "\ntenInt vectors:\n" << endl;
	printVector(v_tenInts);
	deleteVector(v_tenInts);

	vector<int*>v_11Ints = allocateVector(11);
	cout << "---------------------------------\n" << "\n11Int vectors:\n" << endl;
	printVector(v_11Ints);
	deleteVector(v_11Ints);

	vector<int*>v_20Ints = allocateVector(20);
	cout << "---------------------------------\n"<<"\n20Int Vectors:\n" << endl;
	printVector(v_20Ints);
	deleteVector(v_20Ints);

	return 0;
}
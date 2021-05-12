// ArrayDrills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"
//drill 1-Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
int ga[10] = { 1,2,4,8,16,32,64,128,256,512 };

//drill 2&3
void f(int a[], int n)
{
	int la[10];
	
	for (int i = 0; i < n; ++i)
		la[i] = ga[i];

	for (int i = 0; i < n; ++i)
		cout << la[i] << ' ';
	cout << endl;

	int* p = new int[n];

	memcpy(p, a, n * sizeof(int));

	for (int i= 0; i < n; ++i)
		cout << p[i] << ' ';
	cout << endl;

	delete[] p;
}

int fac(int n)
{
	return n > 1 ? n * (fac(n - 1)) : 1;
}

int main()
{
	f(ga, 10);

	int aa[10]={ 1, fac(2),fac(3),fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10) };

	f(aa, 10);


	return 0;

}


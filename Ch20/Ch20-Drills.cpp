// Ch20-Drills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include<array>

template<typename Iterator, typename Out>
Out my_copy(Iterator first, Iterator last, Out res)
{
	while (first != last)
	{
		*res = *first;
		++res;
		++first;
	}
	return res;
}





int main()
{
   //drill 1
	std::array<int,10> a1= { 0,1,2,3,4,5,6,7,8,9 };
	

	//drill 2
	std::vector<int> v1={ 0,1,2,3,4,5,6,7,8,9 };
	

	//drill 3
	std::list<int> l1={ 0,1,2,3,4,5,6,7,8,9 };
	

	//drill 4 copy
	std::array<int,10> a2;

	my_copy(a1.begin(), a1.end(), a2.begin());

	std::vector<int> v2(10);

	my_copy(v1.begin(), v1.end(), v2.begin());

	std::list<int> l2(10);

	my_copy(l1.begin(), l1.end(),l2.begin());

	//drill 5-increase value
	for (int& i : a1) i += 2;
	
	for (int& i : v1) i += 3;

	for (int& i : l1) i += 5;

	//drill 7
	my_copy(a1.begin(), a1.end(), v2.begin());
	if(a1[0] != v2[0])
		std::cout<< "Error: a1[0] && v2[0] are not the same!" << std::endl;

	my_copy(l1.begin(), l1.end(), a2.begin());
	if (*(l1.begin()) != a2[0])
		std::cout << "Error: l1[0] && a2[0] are not the same!" << std::endl;

	//drill 8 find(3)
	auto vRes = find(v1.begin(), v1.end(), 3);
	
	if (vRes != v1.end())
		std::cout << "vRes contains 3 in position:" << distance(v1.begin(), vRes) << std::endl;
	else
		std::cout << "vRes doesn't contain 3" << std::endl;

	//find(27)
	auto lRes = find(l1.begin(), l1.end(), 27);

	if (lRes != l1.end())
		std::cout << "lRes contains 27 in position:" << distance(l1.begin(), lRes) << std::endl;
	else
		std::cout << "lRes doesn't contain 27" << std::endl;


    
	return 0;
}


#include "EasyFind.hpp"
#include <vector>
#include <iostream>
// T print(T &container, int value)

int main()
{
	//std::vector<int> v{0,1,2,3,4,5,6,7,8,9}; // c++11
	std::vector<int> v;

	for(int i=0;i<=9;i++)
		v.push_back(i);
	// v[0] = 999;
	// v[9] = 0;

	// print value
	try
	{
		std::cout << *easyfind(v, 3) << '\n';
		std::cout << *easyfind(v, 9) << '\n';
		std::cout << *easyfind(v, 99) << '\n';	// 존재하지 않는 값
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// print idx
	// try
	// {
	// 	std::cout << easyfind(v, 0) - v.begin() << '\n';
	// 	std::cout << easyfind(v, 9) - v.begin() << '\n';
	// 	std::cout << easyfind(v, 99) - v.begin() << '\n';
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

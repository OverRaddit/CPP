#include "EasyFind.hpp"
#include <vector>
#include <iostream>
// T print(T &container, int value)

int main()
{
	//std::vector<int> v = {0,1,2,3,4,5,6,7};
	std::vector<int> v{0,1,2,3,4,5,6,7,8,9};

	// for(int i=1;i<=10;i++)
	// 	v.push_back(i);

	try
	{
		std::cout << *easyfind(v, 3) << '\n';
		std::cout << *easyfind(v, 9) << '\n';
		std::cout << *easyfind(v, 99) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
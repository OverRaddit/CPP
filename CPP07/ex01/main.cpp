#include <iostream>
#include "iter.hpp"
#include <string>

int main()
{
	int arr[] = {0, 1, 2, 3, 4};
	double arr2[] = {0.1, 1.1, 2.1, 3.1, 4.1};
	float arr3[] = {0.9, 1.9, 2.9, 3.9, 4.9};
	std::string arr4[] = {"one", "two", "three", "four", "five"};

	iter<int>(arr, sizeof(arr)/sizeof(int), print<int>);
	std::cout << std::endl;

	iter<double>(arr2, sizeof(arr2)/sizeof(double), print); // 프린트 템플릿에 자료형을 주지 않아도 앞에서 이미 결정됨.
	std::cout << std::endl;

	iter<float>(arr3, sizeof(arr3)/sizeof(float), print<float>);
	std::cout << std::endl;

	iter<std::string>(arr4, sizeof(arr4)/sizeof(std::string), print<std::string>);
	std::cout << std::endl;

}
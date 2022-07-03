#include <iostream>
#include <string>
#include <iomanip> // setw


int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Each address" << std::endl;
	std::cout << std::setw(25) << std::left << "str's address: " << &str << std::endl;
	std::cout << std::setw(25) << std::left << "stringPTR's address: " << stringPTR << std::endl;
	std::cout << std::setw(25) << std::left << "stringREF's address: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << std::setw(25) << std::left << "Each value" << std::endl;
	std::cout << std::setw(25) << std::left << "str's value: " << str << std::endl;
	std::cout << std::setw(25) << std::left << "stringPTR's value: " << *stringPTR << std::endl;
	std::cout << std::setw(25) << std::left << "stringREF's value: " << stringREF << std::endl;
}
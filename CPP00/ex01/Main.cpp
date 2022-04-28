#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

bool	validate_getline(void)
{
	// if (std::cin.eof())
	// 		return (false);
	// if (std::cin.fail())
	// {
	// 	std::cout << "fail!!\n";
	// 	std::cin.clear();
	// 	std::cin.ignore(1024, '\n');
	// }
	if (std::cin.eof() || std::cin.fail())
	{
		std::cout << "Input Fail\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}
	return (true);
}
#include <iomanip>
int	main()
{
	PhoneBook phonebook = PhoneBook();
	std::string str;

	while(1)
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (!validate_getline())
			return (0);

		if (!str.compare("EXIT"))
			break;
		else if (!str.compare("ADD"))
			phonebook.addContact();
		else if (!str.compare("SEARCH"))
		{
			phonebook.searchContact();
		}
	}
	return (0);
}
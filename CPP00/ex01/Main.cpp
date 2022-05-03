#include <iostream>
#include <string>
#include <limits>

#include "PhoneBook.hpp"
#include "Util.hpp"

int	main()
{
	PhoneBook phonebook = PhoneBook();
	std::string str;
	while(1)
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		validate_input();

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
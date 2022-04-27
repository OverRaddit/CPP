#include <iostream>
#include <string>
#include "PhoneBook.hpp"

bool	validate_getline(void)
{
	if (std::cin.eof())
			return (false);
	if (std::cin.fail())
	{
		std::cout << "fail!!\n";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}

	// 버퍼에 남은 문자제거
	// std::cin.clear();
	// std::cin.ignore(1024, '\n');
	return (true);
}
#include <iomanip>
int	main()
{
	PhoneBook phonebook = PhoneBook();
	std::string str;

	std::cout << std::setw(10);
  	std::cout << 77 << std::endl;

	while(1)
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (!validate_getline())
			return (0);

		if (!str.compare("EXIT"))
			break;
		else if (!str.compare("ADD"))
		{
			phonebook.addContact();
		}
		else if (!str.compare("SEARCH"))
		{
			phonebook.printContacts();

			// 프롬프트를 통해 idx를 입력받아 한 연락처를 출력한다.
			std::cout << "Search index> ";
			//std::getline(std::cin, str);
			int idx;
			std::cin >> idx;
			std::cin.ignore(1024, '\n');

			// idx에 의미없는 입력값이 들어오면 적절히 처리한다.

			// 해당 인덱스에 맞는 contact 출력.
		}


	}
	return (0);
}
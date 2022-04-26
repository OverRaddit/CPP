#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;

	while(1)
	{
		// 문자열을 입력받는다.
		std::string str;
		//std::cin >> str;
		std::getline(std::cin, str);

		if (!str.compare("EXIT"))
			break;

		// 문자열이 ADD
		else if (!str.compare("ADD"))
		{
			// 새 contact를 생성한다.
			Contact contact = new Contact();
			// contact를 phonebook에 추가한다.
		}

		// 문자열이 SEARCH
		else if (!str.compare("SEARCH"))
		{
			// phonebook의 현황을 format에 맞게 출력한다.

			// 프롬프트를 통해 idx를 입력받아 한 연락처를 출력한다.

			// idx에 의미없는 입력값이 들어오면 적절히 처리한다.
		}


	}
	return (0);
}
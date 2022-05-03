#include "PhoneBook.hpp"
#include <cstdio> // void clearerr(FILE* stream);

void	validate_input(void)
{
	if (std::cin.eof() || std::cin.fail())
	{
		std::cout << "Input Fail\n";
		std::cin.clear();
		clearerr(stdin);	// 표준입력fd 0
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook's constructor called!\n";
	nextIdx = 0;
	count = 0;
}

int	PhoneBook::getCount(void)
{
	return count;
}

void PhoneBook::addContact()	// 연락처를 추가한다.
{
	// 다음공간에 저장. 담겨있던 데이터가 존재하면 지워진다.
	contacts[nextIdx].set_info();

	// 다음공간 지정.
	nextIdx = (nextIdx + 1) % 8;
	count = (count == 8) ? count : count + 1;
}

std::string truncate(std::string str, size_t width, bool show_ellipsis=true)
{
	if (str.length() > width)
	{
		if (show_ellipsis)
			return str.substr(0, width) + ".";
		else
			return str.substr(0, width);
	}
	return str;
}

// 10보다 길면 벗어난 범위를 "."으로 대체
void PhoneBook::printContact(int i)
{
	if (i < 0 || i > 7)
		return ;

	std::cout << std::setw(10) << i + 1 << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getLname(), 9) << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getFname(), 9) << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getNname(), 9) << "|" << std::endl;
}

void PhoneBook::printContactAll(int i)
{
	if (i < 0 || i > 7)
		return ;

	std::cout << std::setw(10) << truncate(contacts[i].getFname(), 9) << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getLname(), 9) << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getNname(), 9) << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getPnum(), 9) << "|";
	std::cout << std::setw(10) << truncate(contacts[i].getDsecret(), 9) << "|" << std::endl;
}

void PhoneBook::printHead(void)
{
	std::cout << std::setw(10) << "Idx" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "\n";
	std::cout << std::setfill(' ');
}

void PhoneBook::printHeadAll(void)
{
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::setw(10) << "PhoneNum" << "|";
	std::cout << std::setw(10) << "D_Secret" << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(55) << "\n";
	std::cout << std::setfill(' ');
}

void PhoneBook::printContacts(void)			// 연락처목록을 출력한다.
{
	printHead();
	for(int i = 0 ; i < count ; i++)
		printContact(i);
}

void PhoneBook::searchContact(void)		// 인덱스에 해당하는 연락처를 출력한다.
{
	int idx;

	// 등록된 연락처 x
	if (!getCount())
	{
		std::cout << "There's no Contact :( \n";
		return ;
	}
	printContacts();
	while(1)
	{
		std::cout << "Search index> ";
		std::cin >> idx;
		validate_input();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (idx < 1 || idx > 8)
			std::cout << "Invalid Index" << std::endl;
		else if (idx > getCount())
			std::cout << "There's no Contact Yet." << std::endl;
		else
			break ;
	}
	printHeadAll();
	printContactAll(idx - 1); // idx to num
}
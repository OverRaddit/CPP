#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook's constructor called!\n";
	nextIdx = 0;
	count = 0;
}

void PhoneBook::addContact()	// 연락처를 추가한다.
{
	// 다음공간에 저장. 담겨있던 데이터가 존재하면 지워진다.
	contacts[nextIdx].set_info();

	// 다음공간 지정.
	nextIdx = (nextIdx + 1) % 8;
	count = (count == 8) ? count : count + 1;
}


// 10보다 길면 벗어난 범위를 "."으로 대체
void PhoneBook::printContact(int i)
{
	if (i < 0 || i > 7)
		return ;

	std::cout << std::setw(10);
	std::cout << i + 1 << "|";

	std::cout << std::setw(10);
	std::cout << contacts[i].getLname() << "|";

	std::cout << std::setw(10);
	std::cout << contacts[i].getFname() << "|";

	std::cout << std::setw(10);
	std::cout << contacts[i].getNname() << "|" << std::endl;
}

void PhoneBook::printContacts(void)			// 연락처목록을 출력한다.
{
	// 연락처가 비었다.
	if (count == 0){
		std::cout << "There's no Contact :( \n";
		return ;
	}
	// 연락처가 존재한다.
	std::cout << std::setw(10);
	std::cout << "Idx" << "|";
	std::cout << std::setw(10);
	std::cout << "Lastname" << "|";
	std::cout << std::setw(10);
	std::cout << "Firstname" << "|";
	std::cout << std::setw(10);
	std::cout << "Nickname" << "|" << std::endl;
	for(int i = 0 ; i < count ; i++)
		printContact(i);
}

void PhoneBook::searchContact(int idx)		// 인덱스에 해당하는 연락처를 출력한다.
{

}
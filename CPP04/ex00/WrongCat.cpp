#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& a)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
	*this = a;
}

WrongCat& WrongCat::operator=(const WrongCat& a)
{
	this->type = a.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << std::endl;
}

void WrongCat::special(void) const
{
	std::cout << "WrongCat special function!" << std::endl;
}
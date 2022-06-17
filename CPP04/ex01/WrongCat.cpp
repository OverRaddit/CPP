#include "WrongCat.hpp"

WrongCat::WrongCat() : brain(new Brain())
{
	type = "WrongCat";
	std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& a) : brain(new Brain())
{
	*this = a;
}

WrongCat& WrongCat::operator=(const WrongCat& a)
{
	// 자기자신이 들어왔을때 깊은복사문제발생
	if (this == &a)
		return *this;
	this->type = a.type;

	// Deep copy
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain(*(a.brain));
	return *this;
}

WrongCat::~WrongCat()
{
	delete brain;
	std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << std::endl;
}
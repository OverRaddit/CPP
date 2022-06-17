#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "annonymous";
	std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = a;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	this->type = a.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong....!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}
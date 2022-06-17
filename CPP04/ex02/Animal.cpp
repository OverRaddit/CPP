#include "Animal.hpp"

Animal::Animal()
{
	type = "annonymous";
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(const Animal& a)
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = a;
}

Animal& Animal::operator=(const Animal& a)
{
	this->type = a.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

//순수가상함수!
// void Animal::makeSound() const
// {
// 	std::cout << "....!" << std::endl;
// }

std::string Animal::getType(void) const
{
	return type;
}
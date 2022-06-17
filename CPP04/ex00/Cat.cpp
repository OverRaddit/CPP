#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat& a)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = a;
}

Cat& Cat::operator=(const Cat& a)
{
	this->type = a.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
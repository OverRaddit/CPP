#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog& a)
{
	*this = a;
}

Dog& Dog::operator=(const Dog& a)
{
	this->type = a.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}
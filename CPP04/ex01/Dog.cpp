#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog& a) : brain(new Brain(*a.getBrain()))
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = a;
}

Dog& Dog::operator=(const Dog& a)
{
	if (this == &a)
		return *this;
	this->type = a.type;

	// Deep copy
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain(*(a.brain));
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return brain;
}
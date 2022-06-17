#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat& a) : brain(new Brain(*a.getBrain()))
{
	*this = a;
}

Cat& Cat::operator=(const Cat& a)
{
	this->type = a.type;

	// 깊은 복사가 수행됨.
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain(*(a.brain));
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return brain;
}
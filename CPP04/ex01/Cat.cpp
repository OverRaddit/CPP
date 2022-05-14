#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat& a) : brain(new Brain())
{
	*this = a;
}

Cat& Cat::operator=(const Cat& a)
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
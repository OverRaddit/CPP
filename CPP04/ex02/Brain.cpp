#include "Brain.hpp"

Brain::Brain()
{
	for(int i=0;i<100;i++)
		ideas[i] = "I'm thinking!!";
	std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(const Brain& a)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	*this = a;
}

Brain& Brain::operator=(const Brain& a)
{
	for(int i=0;i<100;i++)
	{
		this->ideas[i] = a.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

void Brain::say(void)
{
	std::cout << "====print Idea====" << std::endl;
	for(int i=0;i<10;i++)
	{
		std::cout << ideas[i] << std::endl;
	}
	std::cout << "==================" << std::endl;
}

void Brain::meditation(void)
{
	for(int i=0;i<100;i++)
	{
		this->ideas[i] = "Inner Peace..";
	}
	std::cout << "Meditaion..." << std::endl;
}
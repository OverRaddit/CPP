#include "Brain.hpp"

Brain::Brain()
{
	for(int i=0;i<100;i++)
		ideas[i] = "I'm thinking!!";
	std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(const Brain& a)
{
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
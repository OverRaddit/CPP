#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal(/* args */);
	~Animal();

	void makeSound();
};

#endif
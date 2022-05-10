//#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	// Create & Fill Array of Animal Object
	Animal *arr[10];
	for(int i=0;i<5;i++)
	{
		arr[i] = new Dog();
	}
	for(int i=5;i<10;i++)
	{
		arr[i] = new Cat();
	}

	// makeSound
	for(int i=0;i<10;i++)
	{
		std::cout << arr[i]->getType() << ", ";
		arr[i]->makeSound();
	}

	// Delete Array
	for(int i=0;i<10;i++)
	{
		delete arr[i];
	}

	delete j;	//should not create a leak
	delete i;

	// memory leaks
	while(1)
	;

	return 0;
}
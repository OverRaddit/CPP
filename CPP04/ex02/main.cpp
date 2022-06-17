//#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	// Create & Fill Array of Animal Object
	Animal *arr[10];
	for(int i=0;i<5;i++)
		arr[i] = new Dog();
	for(int i=5;i<10;i++)
		arr[i] = new Cat();
	std::cout << std::endl;

	// makeSound
	for(int i=0;i<10;i++)
	{
		std::cout << arr[i]->getType() << ", ";
		arr[i]->makeSound();
		//
		arr[i]->getType();
		arr[i]->getBrain()->say();
	}
	std::cout << std::endl;

	// change idea and check deep copy
	Dog dog1;
	Dog dog2(dog1);
	dog1.getBrain()->meditation();
	std::cout << "Original" << std::endl;
	dog1.getBrain()->say();
	std::cout << "Copy" << std::endl;
	dog2.getBrain()->say();
	std::cout << std::endl;

	// Delete Array
	for(int i=0;i<10;i++)
	{
		delete arr[i];			// Animal 포인터를 이용하여 서브클래스 소멸자 호출
		std::cout << std::endl;
	}

	delete i;
	delete j;	//should not create a leak

	// memory leaks
	// while(1)
	// ;

	return 0;
}
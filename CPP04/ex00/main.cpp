//#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* meta = new Animal();

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// std::cout << "==================" << std::endl;
	// Dog A;
	// Cat B;
	// A.makeSound();
	// B.makeSound();
	// std::cout << "==================" << std::endl;

	return 0;
}

// int main() {
// 	// WRONG VERSION
// 	const WrongAnimal* meta = new WrongAnimal();

// 	const Animal* j = new Dog();
// 	const WrongAnimal* i = new WrongCat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	//meta->special();	// there's no special function in WrongAnimal
// }
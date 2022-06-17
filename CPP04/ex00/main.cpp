#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

//#include "Animal.hpp"
// int main() {
// 	const Animal* meta = new Animal();

// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	std::cout << "==================" << std::endl;
// 	Dog A;
// 	Dog A2 = A;	// 초기화할때의 대입연산은 복사생성자를 호출한다.
// 	Dog A3;
// 	A3 = A;		// 그 외의 경우에는 오버로딩한 대입연산자를 호출한다.
// 	Dog A4(A3);
// 	Cat B;
// 	A.makeSound();
// 	A2.makeSound();
// 	A3.makeSound();
// 	A4.makeSound();
// 	B.makeSound();
// 	std::cout << "==================" << std::endl;

// 	delete meta;
// 	delete i;
// 	delete j;

// 	return 0;
// }

// #include "WrongCat.hpp"
// int main() {
// 	// WRONG VERSION
// 	const WrongAnimal* meta = new WrongAnimal();

// 	const WrongAnimal* i = new WrongCat();

// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	meta->makeSound();
// }
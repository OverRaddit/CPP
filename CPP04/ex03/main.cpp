#include "AMateria.hpp"
#include "MateriaSource.hpp"	// learnMateria(new Ice()), createMateria("ice")
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	//std::cout << "0======" << std::endl;

	src->learnMateria(new Ice());	// 2번 생성됨.
	src->learnMateria(new Cure());

	//std::cout << "1======" << std::endl;

	ICharacter* me = new Character("me");

	std::cout << "2======" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);
	std::cout << "3======" << std::endl;

	ICharacter* bob = new Character("bob");
	ICharacter* gshim = new Character("gshim");

	//std::cout << "4======" << std::endl;

	//me->use(0, *bob);
	me->use(1, *gshim);

	std::cout << "5======" << std::endl;

	delete bob;
	std::cout << "6======" << std::endl;

	delete me;
	std::cout << "7======" << std::endl;

	delete src;
	std::cout << "8======" << std::endl;

	return 0;
}


// origin
// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	while(1)
// 	;

// 	return 0;
// }

// int main(){
// 	AMateria *ptr = new Ice();
// 	std::cout << ptr->getType() << "a" << std::endl;

// 	Character *me = new Character("me");
// 	me->equip(ptr);

// 	//delete ptr;
// 	delete me;
// }
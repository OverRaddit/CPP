#include "AMateria.hpp"
#include "MateriaSource.hpp"	// learnMateria(new Ice()), createMateria("ice")
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// int main()
// {
// 	// 선언부
// 	std::cout << "Declaration" << std::endl;
// 	IMateriaSource* src = new MateriaSource();
// 	ICharacter* me = new Character("me");
// 	std::cout << std::endl;

// 	// learn
// 	std::cout << "Learn" << std::endl;
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	std::cout << std::endl;

// 	// create
// 	std::cout << "Create" << std::endl;
// 	// AMateria* tmp;
// 	// tmp = src->createMateria("ice");
// 	// std::cout << tmp->getType() << std::endl;
// 	// delete tmp;
// 	me->equip(src->createMateria("cure"));
// 	me->equip(src->createMateria("ice"));
// 	me->equip(src->createMateria("cure"));
// 	me->equip(src->createMateria("ice"));


// 	//me->unequip(0);

// 	ICharacter* bob = new Character("bob");
// 	ICharacter* gshim = new Character("gshim");

// 	me->use(0, *bob);
// 	me->use(1, *gshim);

// 	// character deep copy check
// 	me->unequip(0);
// 	me->unequip(1);

// 	// delete
// 	delete bob;
// 	delete me;
// 	std::cout << std::endl;
// 	delete src;
// 	std::cout << std::endl;
// 	std::cout << "END" << std::endl;
// 	return 0;
// }

int main()
{
	// 선언부
	std::cout << "Declaration" << std::endl;
	IMateriaSource* src = new MateriaSource();
	Character* me = new Character("me");
	std::cout << std::endl;

	// learn
	std::cout << "Learn" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	// create
	std::cout << "Create" << std::endl;
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));


	//me->unequip(0);

	ICharacter* bob = new Character("bob");
	ICharacter* gshim = new Character("gshim");
	Character* copyman = new Character(*me);

	me->use(0, *bob);
	me->use(1, *gshim);

	// character deep copy check
	me->unequip(0);
	me->unequip(1);

	copyman->use(0, *bob);
	copyman->use(1, *gshim);

	// delete
	delete bob;
	delete me;
	std::cout << std::endl;
	delete src;
	std::cout << std::endl;
	std::cout << "END" << std::endl;
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

// 	// while(1)
// 	// ;

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
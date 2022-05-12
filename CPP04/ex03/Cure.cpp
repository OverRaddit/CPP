#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	type = "cure";
	std::cout << "Cure Constructor" << std::endl;
}

Cure::Cure(std::string const &type) : AMateria()
{
	this->type = type;
	std::cout << "Cure Constructor by type" << std::endl;
}

Cure::Cure(const Cure& a) : AMateria(a)
{
	*this = a;
	type = "cure";
}

Cure& Cure::operator=(const Cure& a)
{
	this->type = a.type;	// 사실상 의미가 없는 복사...
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor" << std::endl;
}


/*
clone() will return a new instance of the same type
(i.e., if you clone an Cure Materia, you will get a new Cure Materia)
*/

AMateria* Cure::clone() const
{
	AMateria *ret = new Cure(*this);
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
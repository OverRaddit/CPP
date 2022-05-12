#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	type = "ice";
	std::cout << "Ice Constructor" << std::endl;
}

Ice::Ice(std::string const &type) : AMateria()
{
	this->type = type;
	std::cout << "Ice Constructor by type" << std::endl;
}

Ice::Ice(const Ice& a) : AMateria(a)
{
	*this = a;
	type = "ice";
}

Ice& Ice::operator=(const Ice& a)
{
	AMateria::operator=(a);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor" << std::endl;
}


/*
clone() will return a new instance of the same type
(i.e., if you clone an Ice Materia, you will get a new Ice Materia)
*/

AMateria* Ice::clone() const
{
	AMateria *ret = new Ice(*this);
	return ret;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
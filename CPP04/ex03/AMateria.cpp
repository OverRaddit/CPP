#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "AMateria";
	this->collectable = true;
	std::cout << "AMateria Constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	this->type = type;
	this->collectable = true;
}

AMateria::AMateria(const AMateria& a)
{
	*this = a;
}

AMateria& AMateria::operator=(const AMateria& a)
{
	this->type = a.type;
	this->collectable = a.collectable;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor" << std::endl;
}

std::string const & AMateria::getType(void) const
{
	return type;
}

bool AMateria::getCollectable(void) const
{
	return collectable;
}
void AMateria::setCollectable(bool flag)
{
	collectable = flag;
}

// 순수 가상함수는 본인의 클래스에서 구현할 수 없다!
// AMateria* AMateria::clone(void) const
// {

// }

// 자식클래스에서 오버라이딩해서 사용될 함수인데 왜 순수 가상함수로 정의하지 않았는지 모르겠다.
// => 가상함수로 선언하지 않은경우 Amateria*로 use함수를 사용할때 Ice::use가 아닌 AMateria::use가 나오는지 확인하려고 그런 듯...?
void AMateria::use(ICharacter& target)
{
	std::cout << "* Use Amataria to " << target.getName() << " *" << std::endl;
}
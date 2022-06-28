#include "Data.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================

Data::Data()
	: name("annonymous"), num(7), a(false)
{}

Data::Data(std::string _name, int n, bool a)
	: name(_name), num(n), a(a)
{}

Data::Data(const Data& a)
{
	*this = a;
}
Data& Data::operator=(const Data& d)
{
	if (this == &d)
		return *this;

	this->name = d.name;
	this->num = d.num;
	this->a = d.a;
	return *this;
}
Data::~Data()
{

}

//=============================================================================
//	Getter
//=============================================================================

std::string Data::getName() const {return name;}
int Data::getNum() const {return num;}
bool Data::getA() const {return a;}

//=============================================================================
//	Outter class Method
//=============================================================================

std::ostream& operator<<(std::ostream& out, const Data& d)
{
	out << "=======Data's info=======\n";
	out << d.getName() << std::endl;
	out << d.getNum() << std::endl;
	out << d.getA() << std::endl;
	out << "=========================\n";
	return out;
}

//=============================================================================
//	Serialization method
//=============================================================================

uintptr_t serialize(Data* ptr)
{
	uintptr_t ret;
	ret = reinterpret_cast<uintptr_t>(ptr);

	return ret;
}

Data* deserialize(uintptr_t raw)
{
	Data* ret;
	ret = reinterpret_cast<Data*>(raw);

	return ret;
}
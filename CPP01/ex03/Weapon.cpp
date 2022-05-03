#include "Weapon.hpp"
#include <iostream>
Weapon::Weapon(void)
{
}

Weapon::~Weapon(void)
{
}

Weapon::Weapon(std::string _type)
{
	type = _type;
}

const std::string& Weapon::getType(void)
{
	return type;
}
void Weapon::setType(std::string _type)
{
	type = _type;
}
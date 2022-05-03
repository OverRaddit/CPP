#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (weapon == NULL)
	{
		std::cout << name << " attacks with their hands!" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}
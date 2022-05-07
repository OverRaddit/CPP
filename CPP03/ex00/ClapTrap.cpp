#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("anonymous"), hp(10), ep(10), damage(0)
{
	std::cout << "ClapTrap created by default" << std::endl;
}
ClapTrap::ClapTrap(std::string _name) : name(_name), hp(10), ep(10), damage(0)
{
	std::cout << "ClapTrap created by name" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	// [2]이게 된다고....? claptrap.name 이렇게 접근 못할 것 같은데...
	name = claptrap.name;
	hp = claptrap.hp;
	ep = claptrap.ep;
	damage = claptrap.damage;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " eliminated " << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target;
	std::cout << ", causing " << damage << " points of damage!" << std::endl;

	ep--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takeDamage " << amount << std::endl;
	hp -= amount;
	if (hp < 0)
		hp = 0;

}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " repaired " << amount;
	std::cout << " points itself" << std::endl;

	hp += amount;
	if (hp >= maxhp)
		hp = maxhp;
	ep--;
}

bool ClapTrap::enoughEnergy(void) const
{
	if (ep == 0 || hp == 0)
	{
		std::cout << "ClapTrap " << name << " Not enough Energy" << std::endl;
		return false;
	}
	else
		return true;
}

unsigned int ClapTrap::getDamage(void) const
{
	return damage;
}

std::string ClapTrap::getName(void) const
{
	return name;
}

void ClapTrap::getStatus(void) const
{
	std::cout << "=======================" << std::endl;
	std::cout << std::setw(10) << "name | " << name << std::endl;
	std::cout << std::setw(10) << "hp | " << hp << std::endl;
	std::cout << std::setw(10) << "ep | " << ep << std::endl;
	std::cout << std::setw(10) << "damage | " << damage << std::endl;
	std::cout << "=======================" << std::endl;
}
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{

}

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name+"_clap_name"), FragTrap(_name+"_clap_name"), ScavTrap(_name+"_clap_name"), name(_name+"_clap_name")
{}

DiamondTrap::DiamondTrap(const DiamondTrap& s)
{
	*this = s;
}

// 이게 맞나?
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& s)
{
	ClapTrap::operator=(s);
	FragTrap::operator=(s);
	ScavTrap::operator=(s);
	this->name = s.name;

	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << getName() << " eliminated " << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName(void) const
{
	return name;
}

unsigned int DiamondTrap::getHP(void) const
{
	return FragTrap::getHp();
}
unsigned int DiamondTrap::getEP(void) const
{
	return ScavTrap::getHp();
}
unsigned int DiamondTrap::getDamage(void) const
{
	return FragTrap::getDamage();
}
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name " << DiamondTrap::name << std::endl;
	std::cout << "ClapTrap Name " << ClapTrap::getName() << std::endl;
}
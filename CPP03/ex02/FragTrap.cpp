#include "FragTrap.hpp"

//[3] 자식클래스 생성자에서 부모클래스 생성자 호출법
FragTrap::FragTrap() : ClapTrap()
{
	setHp(100);
	setEp(100);
	setDamage(30);
	std::cout << "FragTrap created by default" << std::endl;
}
FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	setHp(100);
	setEp(100);
	setDamage(30);
	std::cout << "FragTrap created by name" << std::endl;
}
FragTrap::~FragTrap()
{
	ClapTrap::~ClapTrap();
	std::cout << "FragTrap " << getName() << " eliminated " << std::endl;
}

FragTrap::FragTrap(const FragTrap& s)
{
	*this = s;
}

FragTrap& FragTrap::operator=(const FragTrap& s)
{
	ClapTrap::operator=(s); // [4]
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << getName() << " attacks " << target;
	std::cout << ", causing " << getDamage() << " points of damage!" << std::endl;

	setEp(getEp() - 1);
}

void FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap request you high fives~!!" << std::endl;
}
#include "ScavTrap.hpp"

//[3] 자식클래스 생성자에서 부모클래스 생성자 호출법
ScavTrap::ScavTrap() : ClapTrap()
{
	setHp(100);
	setEp(50);
	setDamage(20);
	std::cout << "ScavTrap created by default" << std::endl;
}
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	setHp(100);
	setEp(50);
	setDamage(20);
	std::cout << "ScavTrap created by name" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " eliminated " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
{
	*this = s;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
	ClapTrap::operator=(s); // [4]
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << getName() << " attacks " << target;
	std::cout << ", causing " << getDamage() << " points of damage!" << std::endl;

	setEp(getEp() - 1);
}

void ScavTrap::guardGate() const
{
	static bool flag;

	flag = !flag;
	if (flag)
		std::cout << "Gate keeper mode activate" << std::endl;
	else
		std::cout << "Gate keeper mode deactivate" << std::endl;
}
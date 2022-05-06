#include "ClapTrap.hpp"

ClapTrap(void) : hp(10), ep(10), damage(0)
{
	std::cout << "ClapTrap created by default" << std::endl;
}
ClapTrap(std::string _name) : name(_name), hp(10), ep(10), damage(0)
{
	std::cout << "ClapTrap created by name" << std::endl;
}
~ClapTrap()
{
	std::cout << "ClapTrap eliminated" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energy == 0)
	{
		enoughEnergy();
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target;
	std::cout << " , causing " << damage << " points of damage!" << std::endl;

	// 적에대한 객체데이터가 없으므로 적의 hp를 감소시킬 수 없다.
	ep--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	// 이 함수에 대한 동작이 subject에 정의되지 않음..
	// 누군가가 공격을 당했을때 정보를 출력하는 함수라고 판단됨.
	std::cout << "ClapTrap " << name << " takeDamage " << amount << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy == 0)
	{
		enoughEnergy();
		return ;
	}
	std::cout << "ClapTrap " << name << " repaired " << amount;
	std::cout << " points itself" << std::endl;

	hp += amount;
	ep--;
}

void ClapTrap::enoughEnergy(void)
{
	std::cout << "ClapTrap " << name << " Not enough Energy" << std::endl;
}

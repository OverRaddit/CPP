#include "HumanA.hpp"

// 참조자는 무조건 이니셜라이저를 통하여 초기화해야 한다.
// 그럼 이니셜라이저는 어떤구조로 초기화를 시키는지?
HumanA::HumanA(std::string _name, Weapon &_weapon) : name(_name), weapon(_weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
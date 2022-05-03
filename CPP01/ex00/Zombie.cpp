#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string _name)
{
	name = _name;
}

Zombie::~Zombie()
{
	std::cout << "[DEBUG] " << name << " destroyed forever!" << std::endl;
}

void Zombie::Announce(void)
{
	std::cout << name << ": Braiiiiiiinnnzzz ..." << std::endl;
}



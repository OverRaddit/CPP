#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie *newzom = newZombie(name);
	newzom->Announce();
	delete newzom;
}
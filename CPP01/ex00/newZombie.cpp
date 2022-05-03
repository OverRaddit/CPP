#include "Zombie.hpp"

// Zombie를 동적으로 할당하여 반환합니다.
Zombie*	newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return newZombie;
}

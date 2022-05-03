#include "Zombie.hpp"

int main()
{
	Zombie *p = zombieHorde(5, "gshim");

	for(int i = 0 ; i < 5 ; i++)
	{
		p[i].Announce();
	}

	delete[] p;

	// Check leaks
	// while(1)
	// 	;

	return (0);
}
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	FragTrap A("Mr.A");
	FragTrap B("Mr.B");
	FragTrap C("practice bot");
	FragTrap D;

	A.getStatus();
	B.getStatus();
	C.getStatus();
	D.getStatus();

	// a attack b
	if (A.enoughEnergy())
	{
		A.attack(B.getName());			// a가 b를 공격
		B.takeDamage(A.getDamage());	// b가 a에게 맞음
	}

	// b repair itself 10 times
	for(int i=0;i<10;i++)
	{
		if (B.enoughEnergy())
		{
			B.beRepaired(1);
			std::cout << "B repaired itself " << i+1 << " times!!" << std::endl;
		}
	}

	// b attack a but fail
	if (B.enoughEnergy())
	{
		B.attack(A.getName());
		A.takeDamage(B.getDamage());
	}

	A.getStatus();
	B.getStatus();
	C.getStatus();
	D.getStatus();

	return 0;
}

#include "DiamondTrap.hpp"
#include <iostream>

int main( void ) {
	DiamondTrap A("Mr.A");
	DiamondTrap B("Mr.B");
	DiamondTrap C("practice bot");
	DiamondTrap D;

	D = C;

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
	for(int i=0;i<100;i++)
	{
		if (B.enoughEnergy())
		{
			B.beRepaired(1);
			//std::cout << "B repaired itself " << i+1 << " times!!" << std::endl;
		}
	}

	// b attack a but fail
	if (B.enoughEnergy())
	{
		B.attack(A.getName());
		A.takeDamage(B.getDamage());
	}

	std::cout << A.getName() << std::endl;
	std::cout << B.getName() << std::endl;
	std::cout << C.getName() << std::endl;
	std::cout << D.getName() << std::endl;

	A.getStatus();
	B.getStatus();
	C.getStatus();
	D.getStatus();

	return 0;
}

#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap A("Mr.A");
	ClapTrap B("Mr.B");
	ClapTrap C("practice bot");
	ClapTrap D;

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
		std::cout << "B repaired itself " << i+1 << " times!!" << std::endl;
		if (B.enoughEnergy())
			B.beRepaired(1);
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

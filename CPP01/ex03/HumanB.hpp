#ifndef HUMANB_H
# include "Weapon.hpp"
# include <iostream>	// attack()

class HumanB
{
private:
	std::string	name;
	Weapon*		weapon;
public:
	HumanB(std::string name);
	~HumanB();

	void attack(void);
	void setWeapon(Weapon &weapon);
};

#endif
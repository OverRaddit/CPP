#ifndef HUMANA_H
#define HUMANA_H
# include "Weapon.hpp"
# include <iostream>	// attack()

class HumanA
{
private:
	std::string	name;
	Weapon&		weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack(void);
};

#endif
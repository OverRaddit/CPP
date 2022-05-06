#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string name;
	unsigned int hp;
	unsigned int ep;
	unsigned int damage;

public:
	ClapTrap();
	ClapTrap(std::string _name);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void enoughEnergy();
};


#endif

/*
claptrap attack -> 공격대상의 hp를 나의 damage만큼 감소시킴
repair-> amount만큼 hp회복
attack/repair -> 1 energy 소비
0 energy -> 아무것도할수없음

*/

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap(/* args */);									// 기본 생성자
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& s);							// 복사 생성자
	DiamondTrap& operator=(const DiamondTrap& s);				// 대입 연산자
	~DiamondTrap();												// 소멸자


	void attack(const std::string& target);	// overriding

	std::string getName(void) const;
	unsigned int getHP(void) const;
	unsigned int getEP(void) const;
	unsigned int getDamage(void) const;
	void whoAmI();
};


#endif
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
private:
	/* data */
public:
	DiamondTrap(/* args */);
	~DiamondTrap();
};


#endif
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{

}

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name), FragTrap(_name), ScavTrap(_name), name(_name)
{

}
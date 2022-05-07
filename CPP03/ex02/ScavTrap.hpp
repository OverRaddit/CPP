#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap();								// 기본 생성자
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& s);			// 복사 생성자
	ScavTrap& operator=(const ScavTrap& s);	// 대입 연산자 오버로딩

	~ScavTrap();							// 소멸자

	void attack(const std::string& target);	// overriding
	void guardGate() const;
};

#endif
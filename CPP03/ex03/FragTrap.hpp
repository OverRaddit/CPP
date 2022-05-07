#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap(/* args */);								// 기본 생성자
	FragTrap(std::string _name);
	FragTrap(const FragTrap& s);						// 복사 생성자
	FragTrap& FragTrap::operator=(const FragTrap& s);	// 대입 연산자
	~FragTrap();										// 소멸자

	void attack(const std::string& target);				// overriding
	void highFivesGuys(void) const;
};

#endif
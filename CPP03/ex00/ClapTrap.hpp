#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <string>
# include <iostream>
# include <iomanip> // setw

class ClapTrap
{
private:
	std::string name;
	unsigned int hp;
	unsigned int ep;
	unsigned int damage;
	static const unsigned int maxhp = 100;			// [1] const로만 해도 가능할까?

public:
	ClapTrap();										// 기본 생성자
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& claptrap);				// 복사 생성자
	ClapTrap& operator=(const ClapTrap& claptrap);	// 대입 연산자 오버로딩
	~ClapTrap();									// 소멸자

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	bool enoughEnergy(void) const;
	unsigned int getDamage(void) const;
	std::string getName(void) const;
	void getStatus(void) const;
};


#endif

/*
claptrap attack -> 공격대상의 hp를 나의 damage만큼 감소시킴
repair-> amount만큼 hp회복
attack/repair -> 1 energy 소비
0 energy -> 아무것도할수없음

*/

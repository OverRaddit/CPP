#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include <string>

class Character : virtual public ICharacter
{
private:
	std::string	name;
	AMateria*	slots[4];

	AMateria*	garbage[100];
	int			g_idx;
//protected:
public:
	Character();								// 기본생성자
	Character(std::string _name);
	Character(const Character& a);				// 복사생성자
	Character& operator=(const Character& a);	// 대입연산자

	virtual ~Character();						// 소멸자
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	int	getNextIdx(void);
};

#endif
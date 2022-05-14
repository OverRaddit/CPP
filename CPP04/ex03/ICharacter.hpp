#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

//# include "AMateria.hpp"
class AMateria;

# include <string>


class ICharacter
{
private:
	/* data */
public:

	virtual int	get_Gidx(void) = 0;

	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif

/*
인터페이스란 순수가상함수로만 이루어진 클래스를 말한다.

기본생성자, 대입연산자, 복사생성자, 소멸자를 virtual로 하지 않는 이상.
Orthodox Canonical Form을 만족시킬 수 없다.
*/
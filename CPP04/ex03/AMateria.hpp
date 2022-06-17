#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;
	bool collectable;	// made by gshim

public:
	AMateria();									// 기본생성자
	AMateria(std::string const &type);
	AMateria(const AMateria& a);				// 복사생성자
	AMateria& operator=(const AMateria& a);		// 대입연산자
	virtual ~AMateria();						// 소멸자

	std::string const & getType(void) const;
	bool const & getCollectable(void) const;	// made by gshim
	void setCollectable(bool flag);				// made by gshim

	virtual AMateria* clone(void) const = 0;	// 스킬객체복사
	virtual void use(ICharacter& target);		// 스킬사용 -> 자식클래스에서 재정의해야 하는 함수. 애초에 왜 순수가상함수로 하지 않은건지?
};

#endif

/*

While assigning a Materia to another, copying the type doesn’t make sense.
객체 내의 type 문자열만 대입하지 말고
실제 동적할당한 객체자체를 대입하라는것 같다.

*/
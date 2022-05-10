#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
protected:
	/* data */
public:
	AMateria();								// 기본생성자
	AMateria(std::string const &type);
	AMateria(const AMateria& a);			// 복사생성자
	AMateria& operator=(const AMateria& a);	// 대입연산자
	~AMateria();							// 소멸자

	std::string const & getType() const;	// returns materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif
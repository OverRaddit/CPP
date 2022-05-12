#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice();									// 기본생성자
	Ice(std::string const &type);
	Ice(const Ice& a);						// 복사생성자
	Ice& operator=(const Ice& a);			// 대입연산자
	virtual ~Ice();							// 소멸자	// 가상함수로?

	virtual AMateria* clone() const;		// 순수가상함수 구현
	virtual void use(ICharacter& target);
};

#endif
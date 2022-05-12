#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure();									// 기본생성자
	Cure(std::string const &type);
	Cure(const Cure& a);					// 복사생성자
	Cure& operator=(const Cure& a);			// 대입연산자
	virtual ~Cure();						// 소멸자	// 가상함수로?

	virtual AMateria* clone() const;		// 순수가상함수 구현
	virtual void use(ICharacter& target);
};


#endif
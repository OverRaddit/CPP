#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal
{
private:
	Brain* brain;	// 접근불가.
public:
	WrongCat();									// 기본생성자
	WrongCat(const WrongCat& a);				// 복사생성자
	WrongCat& operator=(const WrongCat& a);		// 대입연산자
	~WrongCat();								// 소멸자

	void makeSound() const;	// 가상함수
	Brain* getBrain(void) const;
};

#endif
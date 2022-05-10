#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();							// 기본생성자
	Cat(const Cat& a);				// 복사생성자
	Cat& operator=(const Cat& a);	// 대입연산자
	virtual ~Cat();					// 소멸자

	virtual void makeSound() const;	// 가상함수
};

#endif
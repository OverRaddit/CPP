#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();							// 기본생성자
	Dog(const Dog& a);				// 복사생성자
	Dog& operator=(const Dog& a);	// 대입연산자
	virtual ~Dog();					// 소멸자

	virtual void makeSound() const;	// 가상함수
};

#endif
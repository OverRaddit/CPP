#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
	Animal();								// 기본생성자
	Animal(const Animal& a);				// 복사생성자
	Animal& operator=(const Animal& a);		// 대입연산자
	virtual ~Animal();						// 소멸자

	virtual void makeSound() const;			// 가상함수
	virtual Brain* getBrain(void) const = 0;// ㅌㅔ스트용
	std::string getType(void) const;
};

#endif
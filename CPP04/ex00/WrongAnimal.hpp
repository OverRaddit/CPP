#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();									// 기본생성자
	WrongAnimal(const WrongAnimal& a);				// 복사생성자
	WrongAnimal& operator=(const WrongAnimal& a);	// 대입연산자
	~WrongAnimal();									// 소멸자

	void makeSound() const;		// 가상함수
	std::string getType(void) const;
};

#endif
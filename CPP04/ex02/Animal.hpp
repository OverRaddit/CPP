#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();							// 기본생성자
	Animal(const Animal& a);			// 복사생성자
	Animal& operator=(const Animal& a);	// 대입연산자
	virtual ~Animal();					// 소멸자

	virtual void makeSound() const = 0;
	std::string getType(void) const;
};

#endif

int main()
{
	Animal *ptr = new Dog();
}
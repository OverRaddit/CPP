#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();							// 기본생성자
	Brain(const Brain& a);				// 복사생성자
	Brain& operator=(const Brain& a);	// 대입연산자
	~Brain();							// 소멸자

	void say(void);
	void meditation(void);
};


#endif
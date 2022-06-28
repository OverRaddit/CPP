#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
private:
	std::string name;
	int num;
	bool a;
public:
//=============================================================================
//	Getter
//=============================================================================
	std::string getName() const;
	int getNum() const;
	bool getA() const;
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	Data();							// 기본생성자
	Data(std::string _name, int n, bool a);
	Data(const Data& a);			// 복사생성자
	Data& operator=(const Data& a);	// 대입연산자
	~Data();						// 소멸자
};
std::ostream& operator<<(std::ostream& out, const Data& d);

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
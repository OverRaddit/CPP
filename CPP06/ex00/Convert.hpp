#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include <cctype> // isprint
# include <cmath> // isnan

class Convert
{
private:
	bool error;
	const std::string str;
	//const double value;
	double value;
public:
//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
	Convert();								// 기본생성자
	Convert(const std::string& str);
	Convert(const Convert& c);				// 복사생성자
	Convert& operator=(const Convert& c);	// 대입연산자
	~Convert();								// 소멸자
//=============================================================================
//	Method
//=============================================================================
	// toXXXX() 함수
	char toChar(void) const;
	int toInt(void) const;
	float toFloat(void) const;

	// print 함수
	void printChar(void) const;
	void printInt(void) const;
	void printFloat(void) const;
	void printDouble(void) const;
	void printAll(void) const;

	// getter 함수
	bool getError(void) const;
	const std::string& getString(void) const;
	const double& getValue(void) const;

};

#endif
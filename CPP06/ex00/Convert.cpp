#include "Convert.hpp"

//=============================================================================
//	Orthodox Canonical Form
//=============================================================================
Convert::Convert()
{}

// 생성자..
Convert::Convert(const std::string& _str)
	: str(_str)
{
	try
	{
		char *ptr;
		value = std::strtod(str.c_str(), &ptr);

		if (value == 0 && (str[0] != '-' && str[0] != '+' && !std::isdigit(str[0])))
			throw (std::bad_alloc()); // 이게 뭐지?
		if (*ptr && std::strcmp(ptr, "f"))	// 접미사가 f인 경우만 허용한다.
			throw (std::bad_alloc());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Error Occured" << '\n';
	}

}
Convert::Convert(const Convert& c)
{
	*this = c;
}
Convert& Convert::operator=(const Convert& c)
{
	if (this == &c)
		return *this;
	return *this;
}
Convert::~Convert(){}
//=============================================================================
//	Method
//=============================================================================

// toXXXX 함수들 맨위에 error 존재시 적절한 처리가 필요해보임.

char Convert::toChar(void) const
{
	return static_cast<char>(value);
}

int Convert::toInt(void) const
{
	return static_cast<int>(value);
}
float Convert::toFloat(void) const
{
	return static_cast<float>(value);
}

// print 함수
void Convert::printChar(void) const
{
	char ret = toChar();
	if (std::isnan(value))
	{
		std::cout << "impossible";
		return ;
	}
	if (!std::isprint(ret))
	{
		std::cout << "Non displayable";
		return ;
	}
	std::cout << "'" << ret << "'";
}

void Convert::printInt(void) const
{
	int ret = toInt();
	if (std::isnan(value))
	{
		std::cout << "impossible";
		return ;
	}
	std::cout << ret;
}

void Convert::printFloat(void) const
{
	// 소수점을 1자리까지 표현하기로 설정.
	std::cout << std::fixed;
	std::cout.precision(1);

	std::cout << toFloat() << "f";

	// 소수점 고정해제
	std::cout.unsetf(std::ios::fixed);
}

void Convert::printDouble(void) const
{
	// 소수점을 1자리까지 표현하기로 설정.
	std::cout << std::fixed;
	std::cout.precision(1);

	std::cout << getValue();

	// 소수점 고정해제
	std::cout.unsetf(std::ios::fixed);
}

void Convert::printAll(void) const
{
	std::cout << "char: "; printChar();
	std::cout << std::endl;

	std::cout << "int: ";  printInt();
	std::cout << std::endl;

	std::cout << "float: ";printFloat();
	std::cout << std::endl;

	std::cout << "double: ";printDouble();
	std::cout << std::endl;
}

// getter 함수
bool Convert::getError(void) const {return error;}
const std::string& Convert::getString(void) const {return str;}
const double& Convert::getValue(void) const {return value;}
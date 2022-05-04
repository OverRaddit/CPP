#ifndef FIXED_H
#define FIXED_H

# include <iostream>

class Fixed
{
private:
	int rawbits;							// 32비트 raw value
	static const int fractional = 8;		// 소수점 이하 부분을 표현하는 비트의 수를 의미
public:
	//===================================
	// Constructors & Desturctors
	//===================================
	Fixed(void);
	Fixed(const Fixed& fixed);				// 복사 생성자
	Fixed(int n);
	Fixed(float n);
	Fixed& operator=(const Fixed& fixed);	// 복사 대입 연산자
	~Fixed();								// 소멸자

	//===================================
	// Comparison operators
	//===================================
	bool operator>(const Fixed& fixed);
	bool operator<(const Fixed& fixed);
	bool operator>=(const Fixed& fixed);
	bool operator<=(const Fixed& fixed);
	bool operator==(const Fixed& fixed);
	bool operator!=(const Fixed& fixed);

	//===================================
	// Arithmetic operators
	//===================================
	Fixed operator+(const Fixed& fixed);
	Fixed operator-(const Fixed& fixed);
	Fixed operator*(const Fixed& fixed);
	Fixed operator/(const Fixed& fixed);

	//===================================
	// In/decrement operators
	//===================================
	Fixed& operator++(int);					// 후위증가
	Fixed& operator++();					// 전위증가
	Fixed& operator--(int);	// 후위감소
	Fixed& operator--();	// 전위감소
	//Fixed& operator--(const Fixed& fixed);

	//===================================
	// Member functions
	//===================================
	int		getRawBits(void) const;			// 고정소수점값의 raw value를 반환한다.
	void	setRawBits(int const raw);		// 고정소수점수의 raw value를 설정한다.
	float	toFloat(void) const;
	int		toInt(void) const;
};
// << 연산자 오버로딩
std::ostream& operator<< (std::ostream& out, const Fixed& fixed);

#endif
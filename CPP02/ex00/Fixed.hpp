#ifndef FIXED_H
#define FIXED_H

# include <iostream>

class Fixed
{
private:
	int n;										// 32비트 raw value
	static const int fractional = 8;			// 소수점 이하 부분을 표현하는 비트의 수를 의미
public:
	Fixed(/* args */);						// 기본 생성자
	Fixed(const Fixed& fixed);				// 복사 생성자
	Fixed& operator=(const Fixed& fixed);	// 복사 대입 연산자
	~Fixed();								// 소멸자

	int		getRawBits(void) const;			// 고정소수점값의 raw value를 반환한다.
	void	setRawBits(int const raw);		// 고정소수점수의 raw value를 설정한다.
};
#endif

#include "Fixed.hpp"

Fixed::Fixed(void) : rawbits(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int num)
{
	//std::cout << "Int constructor called" << std::endl;
	rawbits = num << fractional;
}

Fixed::Fixed(float num)
{
	//std::cout << "Float constructor called" << std::endl;
	rawbits = roundf(num * (1 << fractional));
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	rawbits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return rawbits;
}
void	Fixed::setRawBits(int const _n)
{
	rawbits = _n;
}

float	Fixed::toFloat(void) const
{
	return (((float)(rawbits) / (1 << fractional) ));
}

int		Fixed::toInt(void) const
{
	return (rawbits >> fractional);
}

// [42]
std::ostream& operator<< (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

// comparison operators
bool Fixed::operator>(const Fixed& fixed) const
{
	return this->toFloat() > fixed.toFloat();
}
bool Fixed::operator<(const Fixed& fixed) const
{
	return this->toFloat() < fixed.toFloat();
}
bool Fixed::operator>=(const Fixed& fixed) const
{
	return this->toFloat() >= fixed.toFloat();
}
bool Fixed::operator<=(const Fixed& fixed) const
{
	return this->toFloat() <= fixed.toFloat();
}
bool Fixed::operator==(const Fixed& fixed) const
{
	return this->toFloat() == fixed.toFloat();
}
bool Fixed::operator!=(const Fixed& fixed) const
{
	return this->toFloat() != fixed.toFloat();
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed ret(this->toFloat() + fixed.toFloat());

	return ret;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed ret(this->toFloat() - fixed.toFloat());

	return ret;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed ret(this->toFloat() * fixed.toFloat());

	return ret;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed ret(this->toFloat() / fixed.toFloat());

	return ret;
}

// In/decrement operators
// ++a
Fixed& Fixed::operator++()
{
	rawbits++;
	return *this;
}

// a++
Fixed Fixed::operator++(int)
{
	Fixed ret(*this);

	rawbits++;
	return ret;
}

// --a
Fixed& Fixed::operator--()
{
	rawbits--;
	return *this;
}

// a--
Fixed Fixed::operator--(int)
{
	Fixed ret(*this);

	rawbits--;
	return ret;
}


const Fixed& Fixed::min(const Fixed& A, const Fixed& B)
{
	if (A <= B)
		return A;
	else
		return B;
}

const Fixed& Fixed::max(const Fixed& A, const Fixed& B)
{
	if (A >= B)
		return A;
	else
		return B;
}

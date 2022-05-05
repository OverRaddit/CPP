#include "Fixed.hpp"
#include <iostream>
int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// my test
	// Fixed x(3);
	// Fixed y(9);

	// std::cout << x * y << std::endl;
	// if (x < y)
	// 	std::cout << "hi";
	// std::cout << (x < y) << std::endl;

	return 0;
}

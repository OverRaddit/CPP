#include <iostream>
#include "whatever.hpp"

// int main()
// {
// 	//int a=1,b=3;
// 	float a=0.9,b=1.5;

// 	std::cout << "BEFORE SWAP" << std::endl;
// 	std::cout << "a: " << a << ", b: " << b << std::endl;
// 	std::cout << "MAX : " << max(a,b) << std::endl;
// 	std::cout << "MIN : " << min(a,b) << std::endl;

// 	swap(a,b);

// 	std::cout << "AFTER SWAP" << std::endl;
// 	std::cout << "a: " << a << ", b: " << b << std::endl;
// 	std::cout << "MAX : " << max(a,b) << std::endl;
// 	std::cout << "MIN : " << min(a,b) << std::endl;
// }

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
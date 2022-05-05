//#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point a(Fixed(-1), Fixed(0));
	Point b(Fixed(1), Fixed(0));
	Point c(Fixed(1), Fixed(2));


	//bool bsp(Point const a, Point const b, Point const c, Point const point)
	for(float i=-1;i<=1.1;i+=0.1)
	{
		Point X(Fixed(i), Fixed(2));
		if (bsp(a,b,c,X))
			std::cout << "X("<< i << ", "<< 2 << ") is inside triangle" << std::endl;
		else
			std::cout << "X("<< i << ", "<< 2 << ") is not inside triangle" << std::endl;
	}



	return 0;
}

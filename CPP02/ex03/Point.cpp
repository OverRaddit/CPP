#include "Point.hpp"

Point::Point(void) : x(0), y(0){}
Point::Point(const Fixed& _x, const Fixed& _y) : x(_x), y(_y) {}
Point::Point(const Point& p) : x(p.getX()), y(p.getY()){}
Point::~Point(){}

// x,y가 const인데 어떻게 대입을 받는거지?
// 1. const를 캐스팅하여 강제로 대입한다.
// 2. 대입을 하지않고 원본을 반환한다.
Point& Point::operator=(const Point& p)
{
	//this = p;
	p;
	return *this;
}

const Fixed& Point::getX(void) const
{
	return x;
}
const Fixed& Point::getY(void) const
{
	return y;
}

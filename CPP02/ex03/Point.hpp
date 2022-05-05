#ifndef POINT_H
#define POINT_H

# include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();								// constructor
	Point(const Fixed& _x, const Fixed& _y);
	Point(const Point& p);					// copy constructor
	~Point();								// destructor

	Point& operator=(const Point& p);	// assignment operator overload

	const Fixed& getX(void) const;	// getter에서 반환값에 const와 참조를 붙일까말까...
	const Fixed& getY(void) const;
	// x,y가 const니까 setter가 불가능하지 않을까?
	// void setX(const Fixed& _x);
	// void setY(const Fixed& _y);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif

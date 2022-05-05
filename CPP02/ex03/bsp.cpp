#include "Point.hpp"

// b에서 반시계방향으로 돌리면 a인지?
int is_clock_b_to_a(float a_xx, float a_yy, float b_xx, float b_yy)
{
	float value = a_xx * b_yy - a_yy * b_xx;

	if (value > 0)
		return 1;
	else if (value < 0)
		return -1;
	else
		return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int flag1 = is_clock_b_to_a(
		a.getX().toFloat() - b.getX().toFloat(),
		a.getY().toFloat() - b.getY().toFloat(),
		b.getX().toFloat() - point.getX().toFloat(),
		b.getY().toFloat() - point.getY().toFloat()
	);
	int flag2 = is_clock_b_to_a(
		b.getX().toFloat() - c.getX().toFloat(),
		b.getY().toFloat() - c.getY().toFloat(),
		c.getX().toFloat() - point.getX().toFloat(),
		c.getY().toFloat() - point.getY().toFloat()
	);
	int flag3 = is_clock_b_to_a(
		c.getX().toFloat() - a.getX().toFloat(),
		c.getY().toFloat() - a.getY().toFloat(),
		a.getX().toFloat() - point.getX().toFloat(),
		a.getY().toFloat() - point.getY().toFloat()
	);
	// check is point is inside of the triangle consist of a, b, c
	//std::cout << flag1 << " " << flag2  << " " << flag3 << std::endl;
	if (flag1 >=0 && flag2 >=0 && flag3 >=0)
		return true;
	if (flag1 <=0 && flag2 <=0 && flag3 <=0)
		return true;
	return false;
}

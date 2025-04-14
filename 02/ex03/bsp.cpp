#include "Point.hpp"

static Fixed	triangleArea(Point const a, Point const b, Point const c)
{
	Fixed result = (a.getX() * (b.getY() - c.getY())
					+ b.getX() * (c.getY() - a.getY())
					+ c.getX() * (a.getY() - b.getY())) / Fixed(2);
	if (result < Fixed(0))
		return result * Fixed(-1);
	return result;
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed total = triangleArea(a, b, c);
	Fixed area1 = triangleArea(p, b, c);
	Fixed area2 = triangleArea(a, p, c);
	Fixed area3 = triangleArea(a, b, p);

	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
		return false;

	return (area1 + area2 + area3 == total);
}
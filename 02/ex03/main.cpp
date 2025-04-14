#include "Point.hpp"
bool	bsp(Point const a, Point const b, Point const c, Point const p);

int main()
{
	Point	a(0, 0);
	Point	b(0, 6);
	Point	c(6, 0);
	Point	p(1, 2);

	if (bsp(a, b, c, p))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	return (0);
}
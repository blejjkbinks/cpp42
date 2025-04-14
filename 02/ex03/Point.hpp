#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(Fixed const x, Fixed const y);
		Point(Point const &p);
		~Point();
		Point &operator=(Point const &other);

		Fixed const &getX() const;
		Fixed const &getY() const;
};

#endif //Point.hpp
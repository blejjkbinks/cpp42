#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Point::";
	std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	std::cout << "Point::";
	std::cout << "Fixed constructor called" << std::endl;
	return;
}

Point::Point(Point const &p) : _x(p.getX()), _y(p.getY())
{
	std::cout << "Point::";
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Point::~Point()
{
	std::cout << "Point::";
	std::cout << "Deconstructor called" << std::endl;
	return;
}

Point &Point::operator=(Point const &other)
{
	std::cout << "Point::";
	std::cout << "Copy assignment called" << std::endl;
	(void)other;
	return (*this);
}

Fixed const &Point::getX() const
{
	return (this->_x);
}

Fixed const &Point::getY() const
{
	return (this->_y);
}
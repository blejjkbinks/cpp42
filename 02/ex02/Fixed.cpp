#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
	return;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
	return;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
	return;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
	return;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const { return this->_value > other._value; }
bool Fixed::operator<(const Fixed &other) const { return this->_value < other._value; }
bool Fixed::operator>=(const Fixed &other) const { return this->_value >= other._value; }
bool Fixed::operator<=(const Fixed &other) const { return this->_value <= other._value; }
bool Fixed::operator==(const Fixed &other) const { return this->_value == other._value; }
bool Fixed::operator!=(const Fixed &other) const { return this->_value != other._value; }

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long tmp = (long)this->_value * (long)other._value;
	result.setRawBits((int)(tmp >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	if (other._value == 0)
	{
		std::cerr << "Division by zero" << std::endl;
		return result;
	}
	long tmp = ((long)this->_value << _fractionalBits) / other._value;
	result.setRawBits((int)tmp);
	return result;
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return a < b ? a : b; }

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }

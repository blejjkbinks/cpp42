#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();
		Fixed &operator=(const Fixed &other);

		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif //Fixed.hpp
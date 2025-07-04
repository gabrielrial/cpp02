#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &);
	~Fixed();

	Fixed &operator=(const Fixed &);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

private:
	int _fixed_point;
	static const int _factorial_bit = 8;
};

#endif

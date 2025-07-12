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

	// Comparasion.
	bool operator<(const Fixed &arg) const;
	bool operator>(const Fixed &arg) const;
	bool operator==(const Fixed &arg) const;
	bool operator!=(const Fixed &arg) const;
	bool operator<=(const Fixed &arg) const;
	bool operator>=(const Fixed &arg) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &Fixed::operator++();
	Fixed &Fixed::operator++(int);
	Fixed &Fixed::operator--();
	Fixed &Fixed::operator--(int);


private:
	int _fixed_point;
	static const int _factorial_bit = 8;
};

#endif

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	if (n > (2147483647 / (1 << _factorial_bit)))
	{
		std::cerr << "Warning: integer too large, value reset to 0" << std::endl;
		_fixed_point = 0;
		return;
	}
	_fixed_point = n << _factorial_bit;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(f * (1 << _factorial_bit));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixed_point = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
		_fixed_point = value.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point = raw;
}

int Fixed::toInt(void) const
{
	return _fixed_point >> _factorial_bit;
}

float Fixed::toFloat(void) const
{
	return (float)_fixed_point / (1 << _factorial_bit);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed &arg) const { return _fixed_point < arg._fixed_point; }
bool Fixed::operator>(const Fixed &arg) const { return _fixed_point > arg._fixed_point; }
bool Fixed::operator==(const Fixed &arg) const { return _fixed_point == arg._fixed_point; }
bool Fixed::operator!=(const Fixed &arg) const { return _fixed_point != arg._fixed_point; }
bool Fixed::operator<=(const Fixed &arg) const { return _fixed_point <= arg._fixed_point; }
bool Fixed::operator>=(const Fixed &arg) const { return _fixed_point >= arg._fixed_point; }

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixed_point + other._fixed_point);
	return result;
}
Fixed Fixed::operator-(const Fixed &arg) const
{
	Fixed result;
	result.setRawBits(_fixed_point * arg._fixed_point);
	return result;
}
Fixed Fixed::operator*(const Fixed &arg) const
{
	Fixed result;
	result.setRawBits(_fixed_point * arg._fixed_point);
	return result;
}
Fixed Fixed::operator/(const Fixed &arg) const
{
	Fixed result;
	result.setRawBits(_fixed_point / arg._fixed_point);
	return result;
}

Fixed &Fixed::operator++()
{
	_fixed_point++;
	return *this;
}

Fixed &Fixed::operator++(int)
{
	Fixed a(*this);
	_fixed_point++;
	return *this;
}

Fixed &Fixed::operator--()
{
	_fixed_point--;
	return *this;
}

Fixed &Fixed::operator--(int)
{
	Fixed a(*this);
	_fixed_point--;
	return *this;
}


Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return a < b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return a > b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return Fixed::min(a, b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return Fixed::max(a, b);
}

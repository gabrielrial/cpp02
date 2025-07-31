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
	_fixed_point = n << _fractional_bit;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(f * (1 << _fractional_bit));
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
	return _fixed_point >> _fractional_bit;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixed_point) / (1 << _fractional_bit);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

// Comparisons
bool Fixed::operator<(const Fixed &arg) const { return _fixed_point < arg._fixed_point; }
bool Fixed::operator>(const Fixed &arg) const { return _fixed_point > arg._fixed_point; }
bool Fixed::operator==(const Fixed &arg) const { return _fixed_point == arg._fixed_point; }
bool Fixed::operator!=(const Fixed &arg) const { return _fixed_point != arg._fixed_point; }
bool Fixed::operator<=(const Fixed &arg) const { return _fixed_point <= arg._fixed_point; }
bool Fixed::operator>=(const Fixed &arg) const { return _fixed_point >= arg._fixed_point; }

// Arithmetic
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixed_point + other._fixed_point);
	return result;
}

Fixed Fixed::operator-(const Fixed &arg) const
{
	Fixed result;
	result.setRawBits(this->_fixed_point - arg._fixed_point);
	return result;
}

Fixed Fixed::operator*(const Fixed &arg) const
{
	Fixed result;
	result.setRawBits((this->_fixed_point * arg._fixed_point) >> _fractional_bit);
	return result;
}

Fixed Fixed::operator/(const Fixed &arg) const
{
	Fixed result;
	if (arg._fixed_point == 0)
	{
		std::cerr << "Division by zero!" << std::endl;
		return Fixed(0);
	}
	result.setRawBits((this->_fixed_point << _fractional_bit) / arg._fixed_point);
	return result;
}

// Increment / Decrement
Fixed &Fixed::operator++() // Prefix
{
	++_fixed_point;
	return *this;
}

Fixed Fixed::operator++(int) // Postfix
{
	Fixed temp(*this);
	++_fixed_point;
	return temp;
}

Fixed &Fixed::operator--() // Prefix
{
	--_fixed_point;
	return *this;
}

Fixed Fixed::operator--(int) // Postfix
{
	Fixed temp(*this);
	--_fixed_point;
	return temp;
}

// Min / Max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

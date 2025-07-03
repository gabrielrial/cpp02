#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
    _fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& value) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value)
        _fixed_point = value.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point = raw;
}
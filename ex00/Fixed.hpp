#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &);
		Fixed& Fixed::operator=(const Fixed& value);

		int getRawBits( void ) const;
		void setRawBits(int const raw);

	private:
		int _fixed_point;
		static const int _factorial_bit = 8;
};

#endif
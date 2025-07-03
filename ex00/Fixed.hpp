#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	~Fixed();

	int getRawBits(void);
	void setRawBits(int const raw);

private:
	int					_fixed_point;
	static const int	_factorial_bit;
};

#endif
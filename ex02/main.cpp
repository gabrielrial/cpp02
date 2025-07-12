#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed const b(20);
	Fixed const c(30);
	Fixed const a(b + c);

	if (b < c)
		std::cout <<" ACAC " << std::endl;
	std::cout << "valor: " << a << std::endl;
	
	return 0;
}
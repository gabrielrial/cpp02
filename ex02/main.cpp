#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed const b(20);
	Fixed const c(30);

	if (b < c)
		std::cout <<" ACAC " << std::endl;
	std::cout << "valor: " << b + c << std::endl;
	
	return 0;
}
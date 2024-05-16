#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	a.setRawBits(10);
	b.setRawBits(2);
	c.setRawBits(20);
	std::cout << "a" << a.getRawBits() << std::endl;
	std::cout << "b" << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int src): _value(0)
{
	this->_value = src << this->_fract;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float src): _value(0)
{
	this->_value = roundf(src * (1 << this->_fract));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	/*std::cout << "getRawBits member function called" << std::endl;*/
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_value / (float)(1 << this->_fract));
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_fract);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

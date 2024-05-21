#include "Point.hpp"

Point::Point()
{
	this->_x.setRawBits(0);
	this->_y.setRawBits(0);
	std::cout << "Standard Point Constructor created" << std::endl;
}

Point::Point(const float x, const float y)
{
	this->_x.setRawBits(x);
	this->_y.setRawBits(y);
	std::cout << "Standard Point Constructor created" << std::endl;
}

Point::Point(Point *src)
{
	*this = src;
	std::cout << "Copy Point Constructor created" << std::endl;
}

Point::~Point()
{
	std::cout << "Standard Point Deconstructor created" << std::endl;
}

Fixed	Point::getX()
{
	return (this->_x);
}

Fixed	Point::getY()
{
	return (this->_y);
}

Point	&Point::operator=(const Point &src)
{
	if (this != &src)
	{
		this->_x.setRawBits(src._x.getRawBits());
		this->_y.setRawBits(src._x.getRawBits());
	}
	return *this;
}

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(Point *src);
		~Point();
		//Copy operator
		Point&	operator=(const Point &src);
		//Getters & setters
		Fixed	getX();
		Fixed	getY();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif

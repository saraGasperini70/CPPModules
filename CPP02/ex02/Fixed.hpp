#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int	_fract;

	public:
	//Constructors and deconstructors
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int src);
		Fixed(const float src);
		~Fixed();
	//Getters/Setters
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		Fixed& 	operator=(const Fixed &src);
	//Comparison operator overloads
		bool	operator>(Fixed fixed) const;
		bool	operator<(Fixed fixed) const;
		bool	operator>=(Fixed fixed) const;
		bool	operator<=(Fixed fixed) const;
		bool	operator==(Fixed fixed) const;
		bool	operator!=(Fixed fixed) const;
	//Arithmetic operator overloads
		float	operator+(Fixed fixed) const;
		float	operator-(Fixed fixed) const;
		float	operator*(Fixed fixed) const;
		float	operator/(Fixed fixed) const;
	//Increment/decrement operators
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
	//Member functions
		float		toFloat( void ) const;
		int			toInt( void ) const;
		static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif

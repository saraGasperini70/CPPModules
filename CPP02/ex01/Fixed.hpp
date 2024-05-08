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
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int src);
		Fixed(const float src);
		~Fixed();
		Fixed& operator=(const Fixed &src);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif

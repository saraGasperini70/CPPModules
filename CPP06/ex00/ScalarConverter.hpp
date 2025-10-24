#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <cmath>
# include <cstdlib>
# include <cfloat>
# include <exception>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		static void convert(std::string str);

	public:
		// Exception classes
		class InvalidInputException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
#endif

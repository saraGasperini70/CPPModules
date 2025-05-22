#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <cfloat>
# include <sstream>
# include <typeinfo>
# include <exception>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		void convert(std::string str);
		void printChar(char c);
		void printInt(int i);
		void printFloat(float f);
		void printDouble(double d);

	private:
		std::string _str;

		// Conversion functions
		void convertChar();
		void convertInt();
		void convertFloat();
		void convertDouble();

	// Helper functions
		bool isChar();
		bool isInt();
		bool isFloat();
		bool isDouble();

	public:
	// Exception classes
	class InvalidInputException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
#endif

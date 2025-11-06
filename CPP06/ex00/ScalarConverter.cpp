#include "ScalarConverter.hpp"
#include <cfloat>
# include <iostream>
# include <limits>
# include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {*this = src;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		*this = src;
	}
	return *this;
}

static bool isPseudoLiteral(const std::string &str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

void printChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void printInt(int i) {
	if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: non displayable" << std::endl;
	}
}

void printFloat(float f) {
	if (f >= FLT_MIN && f <= FLT_MAX) {
		std::cout << "float: " << f << "f" << std::endl;
	} else {
		std::cout << "float: non displayable" << std::endl;
	}
}

void printDouble(double d) {
	if (d >= DBL_MIN && d <= DBL_MAX) {
		std::cout << "double: " << d << std::endl;
	} else {
		std::cout << "double: non displayable" << std::endl;
	}
}

bool isChar(std::string str) {
	if (str.length() == 1 && std::isprint(str[0])) {
		return true;
	}
	return false;
}

bool isInt(std::string str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i]) && str[i] != '-' && str[i] != '+') {
			return false;
		}
	}
	return true;
}

bool isFloat(std::string str) {
	if (str.find('f') == std::string::npos) {
		return false;
	}
	std::string strWithoutF = str;
	strWithoutF.erase(strWithoutF.find('f'), 1);
	for (size_t i = 0; i < strWithoutF.length(); ++i) {
		if (!std::isdigit(strWithoutF[i]) && strWithoutF[i] != '-' && strWithoutF[i] != '+' && strWithoutF[i] != '.') {
			return false;
		}
	}
	return true;
}

bool isDouble(std::string str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i]) && str[i] != '-' && str[i] != '+' && str[i] != '.') {
			return false;
		}
	}
	return true;
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input";
}


void ScalarConverter::convert(std::string str) {
	if (isPseudoLiteral(str)) {
		std::cout << "char: non displayable" << std::endl;
		std::cout << "int: non displayable" << std::endl;
		if (str == "nan" || str == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else if (str == "+inf" || str == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else if (str == "-inf" || str == "-inff") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return;
	}
	std::stringstream sstr;
	sstr << str;
	if (isChar(str)) {
			char c;
			sstr >> c;
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
		}
	else if (isInt(str)) {
			int i;
			sstr >> i;
			printChar(static_cast<char>(i));
			printInt(i);
			printFloat(static_cast<float>(i));
			printDouble(static_cast<double>(i));
		}
	else if (isFloat(str)) {
			float f;
			sstr >> f;
			printChar(static_cast<char>(f));
			printInt(static_cast<int>(f));
			printFloat(f);
			printDouble(static_cast<double>(f));
		}
	else if (isDouble(str)) {
			double d;
			sstr >> d;
			printChar(static_cast<char>(d));
			printInt(static_cast<int>(d));
			printFloat(static_cast<float>(d));
			printDouble(d);
		}
	else
			throw InvalidInputException();
}

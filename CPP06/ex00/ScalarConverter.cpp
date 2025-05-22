#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _str("") {
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter deconstructor called." << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_str = src._str;
	}
	return *this;
}

static bool isPseudoLiteral(const std::string &str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

void ScalarConverter::convertChar() {
	char c = _str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::convertInt() {
	int i = std::stoi(_str);
	printChar(static_cast<char>(i));
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFloat() {
	std::string strWithoutF = _str;
	strWithoutF.erase(strWithoutF.find('f'), 1);
	float f = std::stof(strWithoutF);
	printChar(static_cast<char>(f));
	printInt(static_cast<int>(f));
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::convertDouble() {
	double d = std::stod(_str);
	printChar(static_cast<char>(d));
	printInt(static_cast<int>(d));
	printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::convert(std::string str) {
	this->_str = str;
	if (isPseudoLiteral(_str)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (_str == "nan" || _str == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else if (_str == "+inf" || _str == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else if (_str == "-inf" || _str == "-inff") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return;
	}
	if (isChar()) {
		convertChar();
	} else if (isInt()) {
		convertInt();
	} else if (isFloat()) {
		convertFloat();
	} else if (isDouble()) {
		convertDouble();
	} else {
		throw InvalidInputException();
	}
}

void ScalarConverter::printChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt(int i) {
	if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::printFloat(float f) {
	if (f >= std::numeric_limits<float>::lowest() && f <= std::numeric_limits<float>::max()) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} else {
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::printDouble(double d) {
	if (d >= std::numeric_limits<double>::lowest() && d <= std::numeric_limits<double>::max()) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	} else {
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isChar() {
	if (_str.length() == 1 && std::isprint(_str[0])) {
		return true;
	}
	return false;
}

bool ScalarConverter::isInt() {
	for (size_t i = 0; i < _str.length(); ++i) {
		if (!std::isdigit(_str[i]) && _str[i] != '-' && _str[i] != '+') {
			return false;
		}
	}
	try {
		std::stoi(_str);
	} catch (const std::out_of_range &e) {
		return false;
	} catch (const std::invalid_argument &e) {
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat() {
	if (_str.find('f') == std::string::npos) {
		return false;
	}
	std::string strWithoutF = _str;
	strWithoutF.erase(strWithoutF.find('f'), 1);
	for (size_t i = 0; i < strWithoutF.length(); ++i) {
		if (!std::isdigit(strWithoutF[i]) && strWithoutF[i] != '-' && strWithoutF[i] != '+' && strWithoutF[i] != '.') {
			return false;
		}
	}
	try {
		std::stof(strWithoutF);
	} catch (const std::out_of_range &e) {
		return false;
	} catch (const std::invalid_argument &e) {
		return false;
	}
	return true;
}

bool ScalarConverter::isDouble() {
	for (size_t i = 0; i < _str.length(); ++i) {
		if (!std::isdigit(_str[i]) && _str[i] != '-' && _str[i] != '+' && _str[i] != '.') {
			return false;
		}
	}
	try {
		std::stod(_str);
	} catch (const std::out_of_range &e) {
		return false;
	} catch (const std::invalid_argument &e) {
		return false;
	}
	return true;
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input";
}



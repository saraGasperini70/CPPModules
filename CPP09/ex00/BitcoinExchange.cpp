#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {
	_clearData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

void BitcoinExchange::_loadData(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw FileNotFoundException();
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty()) continue; // Skip empty lines
		std::istringstream iss(line);
		std::string date;
		float value;
		if (!(iss >> date >> value)) {
			throw InvalidValueException();
		}
		if (!_isValidDate(date)) {
			throw InvalidDateException();
		}
		_data[date] = value;
	}
	file.close();
}

bool BitcoinExchange::_isValidDate(const std::string &date) const {
	// Simple date validation (YYYY-MM-DD)
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7) continue; // Skip dashes
		if (!isdigit(date[i])) return false;
	}
	return true;
}

double BitcoinExchange::_parseValue(const std::string &value) const {
	try {
		return std::stod(value);
	} catch (const std::invalid_argument &) {
		throw InvalidValueException();
	} catch (const std::out_of_range &) {
		throw InvalidValueException();
	}
}

void BitcoinExchange::_multiplyValue(std::string &value, double multiplier) const {
	try {
		double val = std::stod(value);
		val *= multiplier;
		value = std::to_string(val);
	} catch (const std::invalid_argument &) {
		throw InvalidValueException();
	} catch (const std::out_of_range &) {
		throw InvalidValueException();
	}
}

std::map<std::string, float> BitcoinExchange::getData() const {
	return _data;
}

void BitcoinExchange::execProgram(const std::string &filename) {
	_loadData(filename);
	if (_data.empty()) {
		throw EmptyFileException();
	}

	for (const auto &entry : _data) {
		std::cout << entry.first << " => " << entry.second << std::endl;
	}
}

void BitcoinExchange::_clearData() {
	_data.clear();
}

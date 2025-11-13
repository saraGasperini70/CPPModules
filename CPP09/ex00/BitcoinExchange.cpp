#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : exchange_rate(src.exchange_rate), multiplier(src.multiplier) {}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> multiplier, std::map<std::string, float> exchange_rate) {
	this->multiplier = multiplier;
	this->exchange_rate = exchange_rate;
}

BitcoinExchange::~BitcoinExchange() {
	this->exchange_rate.clear();
	this->multiplier.clear();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		this->exchange_rate = src.exchange_rate;
		this->multiplier = src.multiplier;
	}
	return *this;
}

void BitcoinExchange::setExchangeRate(std::vector<std::string> exchange) {
	std::cout << "Calling setExchangeRate..." << std::endl;
	this->exchange_rate = aToMap(exchange);
}

void BitcoinExchange::setMultipliers(std::vector<std::string> multi) {
	std::cout << "Calling setMultipliers..." << std::endl;
	this->multiplier = aToMap(multi);
}

void BitcoinExchange::printData() {
	std::cout << "Calling printData..." << std::endl;
	for (std::map<std::string, float>::iterator it = this->exchange_rate.begin(); it != this->exchange_rate.end(); ++it) {
		if (this->multiplier.find(it->first) != this->multiplier.end()) {
			const float result = it->second * this->multiplier[it->first];
			if (result < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (result > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else if (!isValidDate(it->first))
				std::cerr << "Error: bad input => " << it->first << std::endl;
			else
				std::cout << it->first << " =>" << this->multiplier[it->first] << " = " << result << std::endl;
		}
	}
}

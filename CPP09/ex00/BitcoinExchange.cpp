#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

std::map<std::string, float> aToMap(std::vector<std::string> src) { // Should convert a vector to a map, needs to be refactored
	std::string dividers[2] = {",", "|"};
	std::map<std::string, float> returnMap;
	std::cout << "Source string:\n" << src << std::endl;
	size_t pos = src.find("\n", 0);
	std::string header = src.substr(0, pos);
	std::cout << "Pos: " << pos << " Header: " << header << " Header length: " << header.length() << std::endl;
	for (pos = src.substr(header.length(), pos).find("\n"); pos < src.length(); pos++) {
		size_t lineDivider = src.find("\n", pos);
		std::string divider = src.find(dividers[0], pos) != src.npos ? dividers[0] : dividers[1];

		std::string key = src.substr(pos, src.find(divider, pos) - pos);
		std::string value = src.substr (src.find(divider, pos) + 1, lineDivider);
		std::cout << "Key: " << key << " Value: " << value << std::endl;
		returnMap.insert(std::pair<std::string, float>(key, std::atof(value.c_str())));
		pos = lineDivider;
	}
	return returnMap;
}

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
	this->exchange_rate = aToMap(exchange);
}

void BitcoinExchange::setMultipliers(std::vector<std::string> multi) {
	this->multiplier = aToMap(multi);
}

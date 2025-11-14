#include "BitcoinExchange.hpp"
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
	this->exchange_rate = aToMap(exchange);
	std::cout << "Exchange rate data loaded: " << this->exchange_rate.size() << " entries." << std::endl;
}

void BitcoinExchange::setMultipliers(std::vector<std::string> multi) {
	this->multiplier = aToMap(multi);
	std::cout << "Multiplier data loaded: " << this->multiplier.size() << " entries:" << std::endl;
	for (std::map<std::string, float>::iterator it = this->multiplier.begin(); it != this->multiplier.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

void BitcoinExchange::printData() {
	std::vector<std::string> data = dataParse("data.csv");
	std::vector<std::string> input = dataParse("input.txt");
	if (data.empty() || input.empty()) {
		std::cerr << "Error: No data to print." << std::endl;
		return;
	}
	std::vector<std::string>::iterator itd = data.begin();
	std::vector<std::string>::iterator iti = input.begin();
	for (itd = data.begin(); itd != data.end(); ++itd) {
		std::string currDate = itd->substr(0, itd->find(","));
		if (currDate == findNearestDate(input, itd->substr(0, itd->find(",")))) {
			float value1 = ft_atof(iti->substr(iti->find("|") + 1));
			float value2 = ft_atof(itd->substr(itd->find(",") + 1));
			const float result = value2 * value1;
			if (result < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (result > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else if (!isValidDate(currDate))
				std::cerr << "Error: bad input => " << currDate << std::endl;
			else
				std::cout << currDate << " => " << value1 << " = " << result << std::endl;
		}
		if (iti != input.end())
			++iti;
	}
}

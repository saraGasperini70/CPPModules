#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()  {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {

}
BitcoinExchange::BitcoinExchange(std::map<std::string, float> multiplier) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange& operator=(const BitcoinExchange& src) {}
void BitcoinExchange::setExchangeRate(ifstream exchange) {}
void BitcoinExchange::setMultipliers(ifstream multi) {}
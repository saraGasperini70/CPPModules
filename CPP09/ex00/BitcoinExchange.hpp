#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

std::map<std::string, float> aToMap(std::vector<std::string> src);
int ft_atoi(std::string n);
double ft_atof(std::string n);
bool isValidDate(std::string date);
std::string findNearestDate(std::vector<std::string> data, std::string dateToCmp);
std::vector<std::string> dataParse(std::string dataFile);

class BitcoinExchange {
    private:
        std::map<std::string, float> exchange_rate;
        std::map<std::string, float> multiplier;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange(std::map<std::string, float> multiplier, std::map<std::string, float> exchange_rate);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& src);
        void setExchangeRate(std::vector<std::string> exchange);
        void setMultipliers(std::vector<std::string> multi);
        void printData();
};

#endif

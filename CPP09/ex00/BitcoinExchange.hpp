#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <vector>

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
};

#endif

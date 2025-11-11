#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, float> exchange_rate;
        std::map<std::string, float> multiplier;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange(std::map<std::string, float> multiplier);
        ~BitcoinExchange();
        BitcoinExchange BitcoinExchange& operator=(const BitcoinExchange& src);
        void setExchangeRate(std::string exchange);
        void setMultipliers(std::string multi);
};

#endif
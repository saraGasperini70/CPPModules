#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

double ft_atof(std::string n, std::string date);
bool isValidDate(std::string date);
std::map<std::string, double> dataParse(std::string dataFile);
std::string removeSpaces(std::string div);
double validatePrice(std::string const &priceStr);

class BitcoinExchange {
    private:
        std::map<std::string, double> _inputs;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &src);
        std::map<std::string, double> getInputs();
        void setInputs(std::string fileName);
        void printData(std::string file);
        class BadFile : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return "Invalid input file format; should be: date,exchange_rate";
                }
        };
        class NegativeNumber : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return "Error: Negative number is not valid";
                }
        };
        class NumberTooLarge : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return "Error: Number too large: should be between 0 and 1000";
                }
        };
        class InvalidDate : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return "Error: invalid date. Expected format: YYYY-MM-DD";
                }
        };
        class EmptyData : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return "Error: invalid or empty data files";
                }
        };
    };
#endif

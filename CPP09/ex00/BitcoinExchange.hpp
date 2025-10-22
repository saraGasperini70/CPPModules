#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _data;
		void _loadData(const std::string &filename);
		bool _isValidDate(const std::string &date) const;
		double _parseValue(const std::string &value) const;
		void _multiplyValue(std::string &value, double multiplier) const;
		void _clearData();
		public:
		/*Constructors and deconstructor*/
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		/*Methods*/
		std::map<std::string, float> getData() const;
		void execProgram(const std::string &filename);

		/*Exceptions*/
		class InvalidDateException : public std::exception {
			public:
				const char *what() const throw() {
					return "Invalid date format";
				}
		};
		class InvalidValueException : public std::exception {
			public:
				const char *what() const throw() {
					return "Invalid value format";
				}
		};
		class FileNotFoundException : public std::exception {
			public:
				const char *what() const throw() {
					return "File not found";
				}
		};
		class EmptyFileException : public std::exception {
			public:
				const char *what() const throw() {
					return "File is empty";
				}
		};
};

#endif

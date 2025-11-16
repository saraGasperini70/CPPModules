#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	if (this != &src) {
		*this = src;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		*this = src;
	}
	return *this;
}

void BitcoinExchange::printData(std::string file) {
	std::vector<std::string> data = dataParse("data.csv");
	std::vector<std::string> input = dataParse(file);
	std::map<std::string, double> inputMap = aToMap(input);
	if (inputMap.empty() || input.empty()) {
		throw EmptyData();
		return;
	}
	std::vector<std::string>::iterator itd = data.begin();
	std::map<std::string, double>::iterator iti = inputMap.begin();
	if (itd->find("date,exchange_rate") == itd->npos)
		throw BadFile();
	++iti;
	++itd;
	for (iti = inputMap.begin(); iti != inputMap.end(); ++iti) {
		std::string currDate = removeSpaces(iti->first); //This parses correctly
		std::string nearestDate = findNearestDate(data, currDate);
		if (!isValidDate(currDate) || !iti->second) {
			std::cout << "Error: bad input => " << currDate << std::endl;
			continue ;
		}
		long unsigned int i;
		for (i = 0; i < data.size(); i++) {
			if (data[i].find(nearestDate) != data[i].npos)
				break ;
		}
		double value1 = iti->second;
		float value2 = ft_atof(data[i].substr(data[i].find(nearestDate) + nearestDate.length()), data[i].substr(0, data[i].find(",")));

		double result = value2 * value1;
		if (result < 0 || value1 < 0 || value2 < 0) {
			std::cout << "Error: not a positive number" << std::endl;
			continue ;
		}
		if (result > 1000 || value1 > 1000 || value2 > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		std::cout << currDate << " => " << value1 << " = " << result << std::endl;
	}
}


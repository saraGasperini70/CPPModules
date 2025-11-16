#include "BitcoinExchange.hpp"
#include <sstream>

std::map<std::string, double> aToMap(std::vector<std::string> src) {
	std::string dividers[2] = {",", "|"};
	std::map<std::string, double> returnMap;
	long unsigned int pos = 1;
	for (pos = 1; pos < src.size(); ++pos) {
		std::string divider = src[pos].find(dividers[0]) != src[pos].npos ? dividers[0] : dividers[1];
		std::string key = src[pos].substr(0, src[pos].find(divider) - 1);
		double value = validatePrice(src[pos].substr(src[pos].find(divider) + 1));
		std::cout << "Mapped: " << key << " => " << value << std::endl;
		returnMap.insert(std::pair<std::string, double>(key, value));
	}
	return returnMap;
}

int ft_atoi(std::string n, std::string date) {
	int i;
	if (n.compare("null") == 0) {
		std::cout << "(Bad int) Error: bad input =>" << n << date << std::endl;
		n = "-1";
	}
	std::stringstream(n) >> i;
	return (i);
}

double ft_atof(std::string n, std::string date) {
	double i;
	if (n.compare("null") == 0) {
		std::cout << "(Bad float) Error: bad input =>" << n << date << std::endl;
		n = "-1";
	}
	std::stringstream(n) >> i;
	return (i);
}

bool isValidDate(std::string date) {
	//Year-Month-Day
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	bool year = date.substr(0, 4).find_first_not_of("0123456789") == std::string::npos;
	bool month = date.substr(5, 2).find_first_not_of("0123456789") == std::string::npos && ft_atoi(date.substr(5, 2), date) >= 1 && ft_atoi(date.substr(5, 2), date) <= 12;
	bool day = date.substr(8, 2).find_first_not_of("0123456789") == std::string::npos && ft_atoi(date.substr(8, 2), date) >= 1 && ft_atoi(date.substr(8, 2), date) <= 31;
	return (year && month && day);
}

std::string findNearestDate(std::vector<std::string> data, std::string dateToCmp) {
	// If the date used in the input does not exist in your DB then you must use the closest date contained in your DB. Be careful to use the lower date and not the upper one.
	// Using <algorithm> header
	std::vector<std::string>::iterator it = data.begin();
	while (it != data.end() && it->substr(0, it->find(",")) < dateToCmp) {
		++it;
	}
	if (it != data.end()) {
		return dateToCmp;
	} else {
		std::vector<std::string>::iterator lower = data.end();
		if (lower == data.begin()) {
			return *lower;
		}
		else {
			--lower;
			return *lower;
		}
	}
}

std::vector<std::string> dataParse(std::string dataFile) {
    std::ifstream inFile;

    inFile.open(dataFile.c_str());
    if (!inFile.is_open()) {
        std::cout << "Error: " << dataFile << " is not a file or doesn't exist." << std::endl;
        return (std::vector<std::string>());
    }
    std::vector<std::string> data;
    std::string line;
    while (std::getline(inFile, line)) {
        data.push_back(line);
    }
    // std::cout << "Finished reading " << dataFile << " with " << data.size() << " lines." << std::endl;
    inFile.close();
    return (data);
}

std::string removeSpaces(std::string div) {
  for (long unsigned int i = 0; i < div.length(); i++) {
    if (div[i] == ' ') {
      div.erase(i, 1);
    }
  }
    return (div);
}

double validatePrice(std::string const &priceStr) {
	double returnPrice;

	std::stringstream streamValue(priceStr);
	if(!(streamValue >> returnPrice)) {
		std::cout << "Error: bad value input: " << priceStr << std::endl;
		return (-1);
	}
	else if (returnPrice < 0) {
		std::cout << "Error: not a positive number: " << priceStr << std::endl;
	}
	else if (returnPrice > 1000) {
		std::cout << "Error: too large a number: " << priceStr << std::endl;
	}
	return (returnPrice);
}

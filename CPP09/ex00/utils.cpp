#include "BitcoinExchange.hpp"
#include <cctype>
#include <sstream>

std::map<std::string, double> aToMap(std::vector<std::string> src) {
	std::string dividers[2] = {",", "|"};
	std::map<std::string, double> returnMap;
	long unsigned int pos = 1;
	for (pos = 1; pos < src.size(); ++pos) {
		std::string divider = src[pos].find(dividers[0]) != src[pos].npos ? dividers[0] : dividers[1];
		std::string key = src[pos].substr(0, src[pos].find(divider) - 1);
		double value = validatePrice(src[pos].substr(src[pos].find(divider) + 1));
		returnMap.insert(std::pair<std::string, double>(key, value));
	}
	return returnMap;
}

int ft_atoi(std::string n, std::string date) {
	int i;
	if (n.compare("null") == 0) {
		std::cout << "Error: bad input =>" << n << date << std::endl;
		n = "-1";
	}
	std::stringstream(n) >> i;
	return (i);
}

double ft_atof(std::string n, std::string date) {
	double i;
	if (n.find("-") != n.npos) {
		std::cout << "Error: not a positive number: " << n << std::endl;
		return (-1);
	}
	if (n.find("null") != n.npos) {
		std::cout << "Error: bad input =>" << n << date << std::endl;
		return (-1);
	}
	std::stringstream(n) >> i;
	return (i);
}

bool isValidDate(std::string date) {
	//Year-Month-Day
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue ;
		if (isdigit(date[i]) == 0)
			return (false);
	}
	if (date[5] == '0' && date[6] == '0')
		return (false);
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1')
		return (false);

	if (date[8] == '0' && date[9] == '0')
		return (false);
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3')
		return (false);
	return (true);
}

std::map<std::string, double> dataParse(std::string dataFile) {
    std::ifstream inFile;

    inFile.open(dataFile.c_str());
    if (!inFile.is_open()) {
        std::cout << "Error: " << dataFile << " is not a file or doesn't exist." << std::endl;
        return (std::map<std::string, double>());
    }
    std::string line;
	std::string dividers[2] = {",", "|"};
	std::map<std::string, double> returnMap;
	while (std::getline(inFile, line)) {
		std::string divider = line.find(dividers[0]) != line.npos ? dividers[0] : dividers[1];
		std::string key = line.substr(0, line.find(divider) - 1);
		std::string value = line.substr(line.find(divider) + 1);
		returnMap.insert(std::pair<std::string, double>(key, ft_atof(value, key)));
	}
    // std::cout << "Finished reading " << dataFile << " with " << data.size() << " lines." << std::endl;
    inFile.close();
    return (returnMap);
}

double validatePrice(std::string const &priceStr) {
	double returnPrice;

	std::stringstream streamValue(priceStr);
	if(!(streamValue >> returnPrice) || priceStr.find("-") < priceStr.rfind("-")) {
		std::cout << "Error: bad value input: " << priceStr << std::endl;
		return (-1);
	}
	else if (returnPrice < 0) {
		std::cout << "Error: not a positive number: " << priceStr << std::endl;
		return (-1);
	}
	else if (returnPrice > 1000) {
		std::cout << "Error: too large a number: " << priceStr << std::endl;
		return (-1);
	}
	return (returnPrice);
}

std::string removeSpaces(std::string div) {
	for (size_t i = 0; i < div.size(); i++) {
		if (div[i] == ' ')
			div.erase(i, 1);
	}
	return (div);
}

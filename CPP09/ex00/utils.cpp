#include "BitcoinExchange.hpp"
#include <cctype>
#include <sstream>

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
	std::stringstream(n);
	if (!(ss >> i)) {
		std::cout << "Error: bad input =>" << n << date << std::endl;
		return (-1);
	}
	return (i);
}

bool isValidDate(std::string date) {
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
        throw BadFile;
        return (std::map<std::string, double>());
    }
    std::string line;
	std::string dividers[2] = {",", "|"};
	std::map<std::string, double> returnMap;
	while (std::getline(inFile, line)) {
		std::string divider = line.find(dividers[0]) != line.npos ? dividers[0] : dividers[1];
		std::string key = removeSpaces(line.substr(0, line.find(divider)));
		std::string value = line.substr(line.find(divider) + 1);
		returnMap.insert(std::pair<std::string, double>(key, ft_atof(value, key)));
	}
    inFile.close();
    return (returnMap);
}

double validatePrice(std::string const &priceStr) {
	double returnPrice;

	std::stringstream streamValue(priceStr);
	size_t firstMinus = priceStr.find("-");
	size_t lastMinus = priceStr.rfind("-");
	bool multipleMinus = (firstMinus != std::npos && firstMinus != lastMinus);
	if(!(streamValue >> returnPrice) || multipleMinus) {
		throw BadValueInput();
		return (-1);
	}
	else if (returnPrice < 0) {
		throw NegativeNumber();
		return (-1);
	}
	else if (returnPrice > 1000) {
		throw NumberTooLarge();
		return (-1);
	}
	return (returnPrice);
}

std::string removeSpaces(std::string div) {
	div.erase(std::remove(div.begin(), div.end(), ' '));
	return (div);
}

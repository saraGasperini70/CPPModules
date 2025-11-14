#include "BitcoinExchange.hpp"

std::map<std::string, float> aToMap(std::vector<std::string> src) {
	std::string dividers[2] = {",", "|"};
	std::map<std::string, float> returnMap;
	long unsigned int pos = 1;
	for (pos = 1; pos < src.size(); ++pos) {
		std::string divider = src[pos].find(dividers[0]) != src[pos].npos ? dividers[0] : dividers[1];
		std::string key = src[pos].substr(0, src[pos].find(divider));
		std::string value = src[pos].substr(src[pos].find(divider) + 1, src[pos].find(divider.length()));
		std::cout << "Mapped: " << key << " => " << value << std::endl;
		returnMap.insert(std::pair<std::string, float>(key, ft_atof(value.c_str())));
	}
	return returnMap;
}

int ft_atoi(std::string n) {
	int i;
	std::stringstream(n) >> i;
	return (i);
}

double ft_atof(std::string n) {
	double i;
	std::stringstream(n) >> i;
	return (i);
}

bool isValidDate(std::string date) {
	//Year-Month-Day
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	bool year = date.substr(0, 4).find_first_not_of("0123456789") == std::string::npos;
	bool month = date.substr(5, 2).find_first_not_of("0123456789") == std::string::npos && ft_atoi(date.substr(5, 2)) >= 1 && ft_atoi(date.substr(5, 2)) <= 12;
	bool day = date.substr(8, 2).find_first_not_of("0123456789") == std::string::npos && ft_atoi(date.substr(8, 2)) >= 1 && ft_atoi(date.substr(8, 2)) <= 31;
	return (year && month && day);
}

std::string findNearestDate(std::vector<std::string> data, std::string dateToCmp) {
	// If the date used in the input does not exist in your DB then you must use the closest date contained in your DB. Be careful to use the lower date and not the upper one.
	// Using <algorithm> header
	std::vector<std::string>::iterator it = data.begin();
	while (it != data.end() && *it < dateToCmp) {
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
        std::cerr << "Error: " << dataFile << " is not a file or doesn't exist." << std::endl;
        return (std::vector<std::string>());
    }
    std::vector<std::string> data;
    std::string line;
    while (std::getline(inFile, line)) {
        data.push_back(line);
    }
    std::cout << "Finished reading " << dataFile << " with " << data.size() << " lines." << std::endl;
    inFile.close();
    return (data);
}

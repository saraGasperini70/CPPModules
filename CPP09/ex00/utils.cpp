#include <sstream>
#include <iostream>
#include "BitcoinExchange.hpp"

std::map<std::string, float> aToMap(std::vector<std::string> src) {
	std::cout << "Calling aToMap..." << std::endl;
	std::string dividers[2] = {",", "|"};
	std::map<std::string, float> returnMap;
	long unsigned int pos = 1;
	for (pos = 1; pos < src.size(); ++pos) {
		std::string divider = src[pos].find(dividers[0]) != src[pos].npos ? dividers[0] : dividers[1];
		std::string key = src[pos].substr(0, src[pos].find(divider));
		std::string value = src[pos].substr(src[pos].find(divider) + 1, src[pos].find(divider.length()));
		returnMap.insert(std::pair<std::string, float>(key, ft_atof(value.c_str())));
	}
	return returnMap;
}

int ft_atoi(std::string n) {
	std::cout << "Calling ft_atoi..." << std::endl;
	int i;
	std::stringstream(n) >> i;
	return (i);
}

double ft_atof(std::string n) {
	std::cout << "Calling ft_atof..." << std::endl;
	double i;
	std::stringstream(n) >> i;
	return (i);
}

bool isValidDate(std::string date) {
	std::cout << "Calling isValidDate..." << std::endl;
	//Year-Month-Day
	int Year = ft_atoi(date.substr(0, date.find("-")));
	int Month = ft_atoi(date.substr(date.find("-") + 1));
	int Day = ft_atoi(date.substr(date.rfind("-"), date.length()));

	return (Year >= 1900 && Month <= 12 && Day <= 31);
}

std::string findNearestDate(std::map<std::string, float> data, std::string dateToCmp) {
	int Month = ft_atoi(dateToCmp.substr(dateToCmp.find("-") + 1));
	int Day = ft_atoi(dateToCmp.substr(dateToCmp.rfind("-"), dateToCmp.length()));
	int Year = ft_atoi(dateToCmp.substr(0, dateToCmp.find("-")));
	std::map<std::string, float>::iterator it = data.begin();

	for () {
		if (ft_atoi())
	}
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BitcoinExchange.hpp"

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
    inFile.close();
    return (data);
}

int	main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
	}
	else {
		BitcoinExchange BExchange;
		std::vector<std::string> inputData = dataParse(av[1]);
		std::vector<std::string> exchangeRate = dataParse("data.csv");
		BExchange.setExchangeRate(exchangeRate);
		BExchange.setMultipliers(inputData);
        BExchange.printData();
	}
}

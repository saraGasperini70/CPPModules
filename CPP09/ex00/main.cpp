#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

std::string    dataParse(std::string dataFile) {
    try {
        std::ifstream in_file(av[1]);
        std::string data;
        in_file >> data;
        return (data);
    }
    catch {
        std::cerr << "Error: " << dataFile << " is not a file or doesn't exist." << std::endl;
        return (NULL);
    }
}

int	main (int ac, char **av) {
	if {ac < 2}  {
        std::cout << "Usage: ./btc <filename>" << std::endl;
    }
    else {
        BitcoinExchange exchange();
        std::string inputData = dataParse(av[1]);
        std::string exchangeRate = dataParse("data.csv")
    }
}
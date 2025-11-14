#include "BitcoinExchange.hpp"

int	main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
	}
	else {
		BitcoinExchange BExchange;
		std::vector<std::string> inputData = dataParse(av[1]);
		std::vector<std::string> exchangeRate = dataParse("data.csv");
        std::cout << "Loaded " << inputData.size() << " lines from " << av[1] << std::endl;
        std::cout << "Loaded " << exchangeRate.size() << " lines from data.csv" << std::endl;
		BExchange.setExchangeRate(exchangeRate);
		BExchange.setMultipliers(inputData);
        BExchange.printData();
	}
}

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;
		exchange.execProgram(argv[1]);
	} catch (const BitcoinExchange::FileNotFoundException &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const BitcoinExchange::EmptyFileException &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const BitcoinExchange::InvalidDateException &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const BitcoinExchange::InvalidValueException &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

int	main(void)
{
	// Create a Span object with a maximum size of 5
	Span span(5);
	std::vector<int> tinyAdd;
	srand(time(0));
	try {
		for (unsigned int i = 0; i < span.getMaxSize(); ++i) {
			tinyAdd.push_back(rand());
		}
	} catch (...) {
		std::cerr << "Error generating random numbers" << std::endl;
		return 1;
	}

	// Create a span object with a maximum size that is more than 10000
	Span largeSpan(15000);
	std::vector<int> largeAdd;
	srand(time(0));
	try {
		for (unsigned int i = 0; i < largeSpan.getMaxSize(); i++) {
			largeAdd.push_back(rand());
		}
	} catch (...) {
		std::cerr << "Error generating random numbers for large span" << std::endl;
		return 1;
	}

	try {
		// for (unsigned int i = 0; i < span.getMaxSize(); ++i) {
		// 	span.addNumber(tinyAdd[i]);
		// }
		span.addMultipleNumbers(tinyAdd);
		// for (unsigned int i = 0; i < largeSpan.getMaxSize(); ++i) {
		// 	largeSpan.addNumber(largeAdd[i]);
		// }
		largeSpan.addMultipleNumbers(largeAdd);
		std::cout << "Span contents: ";
		for (unsigned int i = 0; i < span.getMaxSize(); ++i) {
			std::cout << span.getNumber(i) << " ";
		}

		std::cout << std::endl << "Large Span contents (first 10 elements): ";
		for (unsigned int i = 0; i < 10; ++i) {
			std::cout << largeSpan.getNumber(i) << " ";
		}

		std::cout << std::endl;

		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;

		std::cout << "Large Span Shortest Span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Large Span Longest Span: " << largeSpan.longestSpan() << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		span.addNumber(10); // This will throw a length_error because the Span is already full (Since it already has 5 numbers)
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

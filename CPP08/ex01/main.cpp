#include "Span.hpp"

int	main(void)
{
	Span span(5);

	try {
		span.addNumber(1);
		span.addNumber(3);
		span.addNumber(7);
		span.addNumber(9);
		span.addNumber(2);

		std::cout << "Span contents: ";
		for (unsigned int i = 0; i < span.getMaxSize(); ++i) {
			std::cout << span.getNumber(i) << " ";
		}
		std::cout << std::endl;

		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		span.addNumber(10); // This will throw a length_error
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
		return 1;
	}

	try
	{
		ScalarConverter converter;
		converter.convert(argv[1]);
	}
	catch (const ScalarConverter::InvalidInputException &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

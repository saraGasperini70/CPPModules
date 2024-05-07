#include "Harl.hpp"

int	main()
{
	Harl harl;

	std::cout << "Testing harl's debug..." << std::endl;
	harl.complain("DEBUG");
	std::cout << "Testing harl's info..." << std::endl;
	harl.complain("INFO");
	std::cout << "Testing harl's warning..." << std::endl;
	harl.complain("WARNING");
	std::cout << "Testing harl's error..." << std::endl;
	harl.complain("ERROR");
}

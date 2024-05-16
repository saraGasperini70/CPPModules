#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;

	if (ac > 1)
	{
		std::cout << "Testing harl's info..." << std::endl;
		harl.complain(av[1]);
	}
}

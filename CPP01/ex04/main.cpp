#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	const std::string	filename = av[1];
	const std::string	search = av[2];
	const std::string	replace = av[3];

	std::ifstream	fin;
	std::ofstream	fout;

	fin.open(av[1]);
}

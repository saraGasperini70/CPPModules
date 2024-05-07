#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

std::string	ft_replace(std::string buffer, std::string search, std::string replace)
{
	size_t	search_len = search.length();
	size_t	replace_len = replace.length();
	size_t	pos_search = 0;

	pos_search = buffer.find(search);
	while (pos_search != std::string::npos)
	{
		buffer.erase(pos_search, search_len);
		buffer.insert(pos_search, replace);
		pos_search = buffer.find(search, pos_search + replace_len);
	}
	return (buffer);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		const std::string	filename = av[1];
		const std::string	search = av[2];
		const std::string	replace = av[3];

		std::string			buffer;
		std::ifstream	fin;
		std::ofstream	fout;

		fin.open(av[1]);
		if (fin.is_open() == true)
		{
			fout.open(".replace", std::ios::out | std::ios::trunc);
			if (fout.is_open() == true)
			{
				while (std::getline(fin, buffer))
				{
					buffer = ft_replace(buffer, search, replace);
					fout << buffer;
					if (fin.peek() != EOF)
						fout << std::endl;
				}
				fout.close();
			}
			else
			{
				std::perror("Error while opening output file.");
				fin.close();
				return (EXIT_FAILURE);
			}
		}
		else
		{
			std::perror("Error while opening input file.");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	else
	{
		std::perror("Number of argument must be 3");
		std::cout << "Usage: filename, search string, replace string." << std::endl;
	}
	return (EXIT_FAILURE);
}

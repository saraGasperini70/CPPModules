#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac >= 2)
	{
		for (i = 1; av[i]; i++)
		{
			for (j = 0; av[i][j]; j++)
				std::cout << (char) toupper(av[i][j]);
			if (i < ac - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

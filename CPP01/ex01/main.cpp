#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int	i;
	int	size = 10;
	Zombie	*horde = zombieHorde(size, "Eldritch");

	for (i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

int	main(void)
{
	Zombie *z = newZombie("Ephraim");

	z->announce();
	randomChump("Vasily");
	delete z;
}

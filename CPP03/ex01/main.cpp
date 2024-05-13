#include "ScavTrap.hpp"

int	main()
{
	ClapTrap hank("Hank");
	ScavTrap danny("Danny");

	hank.attack("Mark");
	danny.attack("Random dude");
	hank.takeDamage(3);
	danny.takeDamage(5);
	hank.beRepaired(3);
	danny.beRepaired(7);
	hank.takeDamage(10);
	danny.takeDamage(12);
	hank.attack("Mark");
	danny.attack("Random dude");
	danny.guardGate();
	return (0);
}

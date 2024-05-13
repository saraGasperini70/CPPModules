#include "FragTrap.hpp"

int	main()
{
	ClapTrap hank("Hank");
	FragTrap danny("Danny");

	hank.attack("Mark");
	danny.attack("Random dude");
	hank.takeDamage(3);
	danny.takeDamage(5);
	hank.beRepaired(3);
	danny.beRepaired(7);
	hank.takeDamage(10);
	danny.takeDamage(12);
	danny.highFivesGuys();
	hank.attack("Mark");
	danny.attack("Random dude");
	return (0);
}

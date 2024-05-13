# include "ScavTrap.hpp"

ScavTrap()
{
	std::cout << "Standard constructor called for ScavTrap" << std::endl;
}

ScavTrap(std::string name)
{
	this->_name = name;
	std::cout << "Standard constructor for ScavTrap " << this->_name << " called." << std::endl;
}

ScavTrap(const ScavTrap &scavtrap)
{
	*this = scavtrap;
	std::cout << "Copy constructor for Scavtrap " << this->_name << " called." << std::endl;
}

~ScavTrap();
std::string getName();
int		getHitPoints();
int		getEnergyPoints();
int		getAttackDamage();
void guardGate();

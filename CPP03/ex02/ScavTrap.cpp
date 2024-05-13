# include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Standard constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Standard constructor for ScavTrap " << this->_name << " called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap)
{
	*this = scavtrap;
	std::cout << "Copy constructor for Scavtrap " << this->_name << " called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Standard deconstructor called for ScavTrap " << this->_name << std::endl;
}

std::string ScavTrap::getName()
{
	return (this->_name);
}

int		ScavTrap::getHitPoints()
{
	return (this->_hitPoints);
}

int		ScavTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}

int		ScavTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " entered Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "ScavTrap " << this->getName() << " is attacking " << target << " for " << this->getAttackDamage() << " points" << std::endl;
	}
	else if (this->getEnergyPoints() <= 0)
		std::cout << "ScavTrap " << this->getName() << " has no energy to attack." << std::endl;
	else if (this->getHitPoints() <= 0)
		std::cout << "ScavTrap " << this->getName() << " has been destroyed and cannot attack anymore." << std::endl;
}

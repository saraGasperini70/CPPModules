# include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Standard constructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Standard constructor for FragTrap " << this->_name << " called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap): ClapTrap(fragtrap)
{
	*this = fragtrap;
	std::cout << "Copy constructor for Fragtrap " << this->_name << " called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Standard deconstructor called for FragTrap " << this->_name << std::endl;
}

std::string FragTrap::getName()
{
	return (this->_name);
}

int		FragTrap::getHitPoints()
{
	return (this->_hitPoints);
}

int		FragTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}

int		FragTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " High fived you!" << std::endl;
}

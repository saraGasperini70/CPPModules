#include "ClapTrap.hpp"

// Constructors/deconstructor
ClapTrap::ClapTrap()
{
	this->_name = "Danny";
	std::cout << "ClapTrap standard constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_name = name;
	std::cout << "ClapTrap standard constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap deconstructor called for " << this->_name << std::endl;
}

//Getters
std::string ClapTrap::getName()
{
	return (this->_name);
}
int	ClapTrap::getHitPoints()
{
	return (this->_hitPoints);
}
int	ClapTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}
int	ClapTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

//Member functions
void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
		std::cout << this->getName() << " is attacking " << target << " for " << this->getAttackDamage() << " points" << std::endl;
	else if (this->getEnergyPoints() <= 0)
		std::cout << this->getName() << " has no energy to attack." << std::endl;
	else if (this->getHitPoints() <= 0)
		std::cout << this->getName() << " has been destroyed and cannot attack anymore." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << this->getName() << " received " << amount << " points of damage. It still has " << this->getHitPoints() << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << this->getName() << " repaired itself for " << amount << " hit points. It now has " << this->getHitPoints() <<  " hit points." << std::endl;
}

//Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_name = src._name;
	return *this;
}

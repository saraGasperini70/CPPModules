#include "ClapTrap.hpp"

ClapTrap::_hitPoints = 10;
ClapTrap::_energyPoints = 10;
ClapTrap::_attackDamage = 0

// Constructors/deconstructor
ClapTrap::ClapTrap(std::string name)
{
	this->_name = name
	std::cout << "ClapTrap standard constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	this = claptrap;
	std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap();
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
	return (this->_energyPoints)
}
int	ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}

void	attack(const std::string &target)
{
	std::cout << this->getName() << " is attacking " << target << " for " this->getAttackDamage() << " points" << std::endl;
}

void	takeDamage(unsigned int amount)
{
	
}

void	beRepaired(unsigned int amount);

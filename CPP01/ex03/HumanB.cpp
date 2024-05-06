#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " created." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " destroyed." << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_armed == 1)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_armed = 1;
}

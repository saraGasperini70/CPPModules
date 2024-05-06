#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name << " created with " << this->_weapon.getType() << "." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " died." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

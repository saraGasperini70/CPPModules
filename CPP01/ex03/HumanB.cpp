#include "HumanA.hpp"

HumanA::HumanB(std::string name)
{
	this._name = name;
	std::cout << this._name << " created." << std::endl;
}

HumanA::~HumanB()
{
	std::cout << this._name << " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this._name << " attacks with their " << this._weapon.type << std::endl;
}

void	HumanA::setWeapon(Weapon *weapon)
{
	this._weapon = weapon;
}

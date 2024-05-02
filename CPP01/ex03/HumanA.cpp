#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this._name = name;
	this._weapon = weapon;
	std::cout << this._name << " created with " << this.weapon.type << "." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this._name << " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this._name << " attacks with their " << this._weapon.type << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this._weapon = weapon;
}

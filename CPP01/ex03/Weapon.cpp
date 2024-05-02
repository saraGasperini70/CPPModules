#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon " << this.type << " created." << std::endl:
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this.type << " destroyed." << std::endl:
}

const std::string	Weapon::getType(void)
{
	return this._type;
}


void	Weapon::setType(std::string type)
{
	this._type = type;
}


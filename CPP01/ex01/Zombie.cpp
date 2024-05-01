#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie " << this->_name << " created." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie " << this->_name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destroyed." << std::endl;
}

//Getter(s)
std::string	Zombie::getName(void)
{
	return this->_name;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

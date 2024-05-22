#include "Character.hpp"

Character::Character(std::string name)
{
	std::cout << "Standard Character constructor called." << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
}

Character::Character(Character *src)
{
	std::cout << "Copy Character constructor called." << std::endl;
	*this = src;
}

Character::~Character()
{
	std::cout << "Standard Character deconstructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
	}
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_name = src._name;
	return *this;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_floor[i] == NULL && this->_inventory[idx] != NULL)
		{
			this->_floor[i] = this->_inventory[idx];
			std::cout << "Materia " << this->_inventory[idx]->getType() << " unequipped." << std::endl;
			this->_inventory[idx] = NULL;
			return ;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	this->_inventory[idx]->use(target);
}




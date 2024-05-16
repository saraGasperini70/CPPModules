#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal standard constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal copy deconstructor called." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "You shouldn´t see this!." << std::endl;
}

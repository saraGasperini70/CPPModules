#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal standard constructor called." << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal standard deconstructor called." << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
void Animal::setType(std::string type)
{
	this->type = type;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "You shouldn´t see this!." << std::endl;
}

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal standard constructor called." << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal copy deconstructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void	Animal::makeSound()
{
	std::cout << "You shouldn´t see this!." << std::endl;
}

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor for Dog called." << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog *src)
{
	std::cout << "Copy constructor for Dog called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Default deconstructor for Dog called." << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment operator called for Dog" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof, woof!" << std::endl;
}

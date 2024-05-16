#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor for Dog called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog *src)
{
	std::cout << "Copy constructor for Dog called." << std::endl;
	//*this = src;
	this->brain = new Brain();
	this->type = src->getType();
}

Dog::~Dog()
{
	std::cout << "Default deconstructor for Dog called." << std::endl;
	delete this->brain;
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

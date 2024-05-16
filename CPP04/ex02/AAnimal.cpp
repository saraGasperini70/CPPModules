#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal standard constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal &src)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal standard deconstructor called." << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}
void AAnimal::setType(std::string type)
{
	this->type = type;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout << "You shouldn't see this!." << std::endl;
}

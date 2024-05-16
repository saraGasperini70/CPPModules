#include "ADog.hpp"

ADog::ADog()
{
	std::cout << "Default constructor for ADog called." << std::endl;
	this->type = "ADog";
	this->brain = new Brain();
}

ADog::ADog(ADog *src)
{
	std::cout << "Copy constructor for ADog called." << std::endl;
	//*this = src;
	this->brain = new Brain();
	this->type = src->getType();
}

ADog::~ADog()
{
	std::cout << "Default deconstructor for ADog called." << std::endl;
	delete this->brain;
}

ADog &ADog::operator=(const ADog &src)
{
	std::cout << "Copy assignment operator called for ADog" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	ADog::makeSound(void) const
{
	std::cout << "Woof, woof!" << std::endl;
}

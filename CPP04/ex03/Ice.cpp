#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Standard Ice constructor called." << std::endl;
	this->_type = "ice";
}

Ice::Ice(Ice &src) : AMateria(src)
{
	std::cout << "Copy Ice constructor called." << std::endl;
	*this = src;
}

Ice::~Ice()
{
	std::cout << "Standard Cure deconstructor called." << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria *newMat = new Ice();

	return (newMat);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

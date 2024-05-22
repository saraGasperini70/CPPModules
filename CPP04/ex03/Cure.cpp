#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	std::cout << "Standard Cure constructor called." << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure &src) : AMateria(src)
{
	std::cout << "Copy Cure constructor called." << std::endl;
	*this = src;
}

Cure::~Cure()
{
	std::cout << "Standard Cure deconstructor called." << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria *newMat = new Cure();

	return (newMat);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

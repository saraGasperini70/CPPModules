#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Standard AMateria constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "Standard AMateria constructor called." << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria &src)
{
	std::cout << "Copy AMateria constructor called." << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "Standard AMateria deconstructor called." << std::endl;
}

std::string const &AMateria::getType() const //Returns the materia type
{
	return (this->_type);
}

void AMateria::setType(std::string type)
{
	this->_type = type;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

// AMateria *AMateria::clone() const
// {
// 	AMateria	*dest = new AMateria;
// 	dest = *this;
// 	return (dest);
// }

void AMateria::use(ICharacter& target)
{
	std::cout << "Using a materia on " << target.getName() << std::endl;
}

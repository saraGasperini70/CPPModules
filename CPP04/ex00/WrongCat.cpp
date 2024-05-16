#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default constructor for WrongCat called." << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat *src)
{
	std::cout << "Copy constructor for WrongCat called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "Default deconstructor for WrongCat called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Copy assignment operator called for WrongCat" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

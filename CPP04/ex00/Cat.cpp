#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor for Cat called." << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat *src)
{
	std::cout << "Copy constructor for Cat called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Default deconstructor for Cat called." << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Copy assignment operator called for Cat" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

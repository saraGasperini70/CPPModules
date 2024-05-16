#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor for Cat called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat *src)
{
	std::cout << "Copy constructor for Cat called." << std::endl;
	//*this = src;
	this->brain = new Brain();
	this->type = src->getType();
}

Cat::~Cat()
{
	std::cout << "Default deconstructor for Cat called." << std::endl;
	delete this->brain;
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

# include "Brain.hpp"

//Constructors/deconstructor
Brain::Brain()
{
	std::cout << "Standard Brain constructor called." << std::endl;
}

Brain::Brain(Brain &src)
{
	std::cout << "Copy Brain constructor called." << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called." << std::endl;
}

//Member functions
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		*this->ideas = *src.ideas;
	return *this;
}

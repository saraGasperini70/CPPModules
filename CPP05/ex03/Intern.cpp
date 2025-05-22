#include "Intern.hpp"

//Constructor/deconstructor
Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor called." << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		// No members to assign
	}
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *form = NULL;
	std::string formTypes[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3)
	{
		if (formName == formTypes[i])
			break;
		i++;
	}

	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Intern can't create " << formName << " form." << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << formName << " form." << std::endl;
	return form;
}

std::ostream &operator<<(std::ostream &out, const Intern &src)
{
	out << "Intern object." << std::endl;
	return (out);
}

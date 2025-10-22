#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	if (formName.empty() || target.empty()) {
		std::cout << "Form name or target cannot be empty." << std::endl;
		return NULL;
	}

	if (formName.find(" ") != std::string::npos) {
		formName[0] = toupper(formName[0]);
		for (size_t spaceIndex = formName.find(" "); spaceIndex != std::string::npos; spaceIndex = formName.find(" ", spaceIndex + 1)) {
			formName[spaceIndex + 1] = toupper(formName[spaceIndex + 1]);
			formName.erase(spaceIndex, 1);
		}

	}
	if (formName.find("Form") == std::string::npos) {
		formName += "Form";
	}

	int i;
	for (i = 0; i < 3; i++) {
		if (formName == formTypes[i])
			break;
	}

	switch (i) {
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
			std::cout << "Intern can't create " << formName << " because it doesn't exist." << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << formName << std::endl;
	return form;
}

std::ostream& operator<<(std::ostream& out, const Intern&)
{
	out << "Intern object." << std::endl;
	return out;
}

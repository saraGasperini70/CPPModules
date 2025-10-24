#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//Constructor/deconstructor
PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src), target(src.target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor called." << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &src)
{
	out << "PresidentialPardonForm name: " << src.getName() << std::endl;
	out << "PresidentialPardonForm sign grade: " << src.getSignGrade() << std::endl;
	out << "PresidentialPardonForm execute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		// this->target = src.target; // Cannot assign to const member
	}
	return *this;
}


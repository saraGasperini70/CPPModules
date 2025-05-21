#include "AForm.hpp"
//Constructor/deconstructor
AForm::AForm(void): toSignGrade(150), toExecuteGrade(150)
{
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): name(name), toSignGrade(signGrade), toExecuteGrade(executeGrade)
{
	std::cout << "AForm constructor called." << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
}
AForm::AForm(const AForm &src) : name(src.name), toSignGrade(src.toSignGrade), toExecuteGrade(src.toExecuteGrade)
{
	std::cout << "AForm copy constructor called." << std::endl;
	*this = src;
}
AForm::~AForm()
{
	std::cout << "AForm deconstructor called." << std::endl;
}
//Getters/Setters
std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->toSignGrade);
}

int AForm::getExecuteGrade(void) const
{
	return (this->toExecuteGrade);
}

// Removed setName method as 'name' is a const member and cannot be modified.

void AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "AForm name: " << src.getName() << std::endl;
	out << "AForm sign grade: " << src.getSignGrade() << std::endl;
	out << "AForm execute grade: " << src.getExecuteGrade() << std::endl;
	out << "AForm is signed: " << (src.getIsSigned() ? "Yes" : "No") << std::endl;
	return out;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->toSignGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed.");
}

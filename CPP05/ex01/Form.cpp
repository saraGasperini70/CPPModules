#include "Bureaucrat.hpp"
#include "Form.hpp"
//Constructor/deconstructor
Form::Form(void): toSignGrade(150), toExecuteGrade(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): name(name), toSignGrade(signGrade), toExecuteGrade(executeGrade)
{
	std::cout << "Form constructor called." << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	this->isSigned = false;
}
Form::Form(Form &src) : name(src.name), toSignGrade(src.toSignGrade), toExecuteGrade(src.toExecuteGrade)
{
	std::cout << "Form copy constructor called." << std::endl;
	*this = src;
}
Form::~Form()
{
	std::cout << "Form deconstructor called." << std::endl;
}
//Getters/Setters
std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->toSignGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->toExecuteGrade);
}

// Removed setName method as 'name' is a const member and cannot be modified.

void Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << "Form name: " << src.getName() << std::endl;
	out << "Form sign grade: " << src.getSignGrade() << std::endl;
	out << "Form execute grade: " << src.getExecuteGrade() << std::endl;
	out << "Form is signed: " << (src.getIsSigned() ? "Yes" : "No") << std::endl;
	return out;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->toSignGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

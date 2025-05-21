#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <string>

//Constructor/deconstructor
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), target(src.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor called." << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::fstream fileout;

	fileout.open((this->target + "_shrubbery").c_str(), std::ios::out);
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	if (!fileout)
	{
		std::cerr << "Error: Could not create file " << this->target + "_shrubbery" << std::endl;
		return;
	}
	std::cout << "ShrubberyCreationForm: " << this->target + "_shrubbery" << " created." << std::endl;
	fileout << "        *           *\n";
	fileout << "       ***         ***\n";
	fileout << "      *****       *****\n";
	fileout << "     *******     *******\n";
	fileout << "       | |         | |\n";
	fileout.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out << "ShrubberyCreationForm name: " << src.getName() << std::endl;
	out << "ShrubberyCreationForm sign grade: " << src.getSignGrade() << std::endl;
	out << "ShrubberyCreationForm execute grade: " << src.getExecuteGrade() << std::endl;
	out << "ShrubberyCreationForm is signed: " << (src.getIsSigned() ? "Yes" : "No") << std::endl;
	return out;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	(void)src;
	return *this;
}

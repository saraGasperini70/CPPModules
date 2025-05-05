#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//Constructor/deconstructor
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm(src), target(src.target)
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

void ShrubberyCreationForm::setTarget(std::string target)
{
	this->target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->target = src.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
	{
		std::ofstream file(this->target + "_shrubbery");
		if (file.is_open())
		{
			file << "       _-_-_\n";
			file << "    _-       -_\n";
			file << "  _-             -_\n";
			file << " -                 -\n";
			file << "        | |\n";
			file.close();
		}
	}
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out << "ShrubberyCreationForm name: " << src.getName() << std::endl;
	out << "ShrubberyCreationForm sign grade: " << src.getSignGrade() << std::endl;
	out << "ShrubberyCreationForm execute grade: " << src.getExecuteGrade() << std::endl;
	out << "ShrubberyCreationForm is signed: " << (src.getIsSigned() ? "Yes" : "No") << std::endl;
	return out;
}


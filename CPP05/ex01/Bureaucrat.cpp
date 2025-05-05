# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : name(src.name)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat deconstructor called." << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->grade = src.grade;
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->name << " couldn't sign " << form.getName() << " because his grade is too low." << std::endl;
}

void Bureaucrat::executeForm(Form const &form)
{
	if (form.getIsSigned())
		std::cout << this->name << " executed " << form.getName() << std::endl;
	else
		std::cout << this->name << " couldn't execute " << form.getName() << " because it is not signed." << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return out;
}

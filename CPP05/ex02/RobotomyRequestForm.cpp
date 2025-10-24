#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), target(src.target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor called." << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "50% chance of success." << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target << " has failed to be robotomized." << std::endl;
}
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &src)
{
	out << "RobotomyRequestForm name: " << src.getName() << std::endl;
	out << "RobotomyRequestForm sign grade: " << src.getSignGrade() << std::endl;
	out << "RobotomyRequestForm execute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		// this->target = src.target; // Cannot assign to const member
	}
	return *this;
}

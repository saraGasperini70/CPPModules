#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("John", 1);
	ShrubberyCreationForm shrubbery;
	RobotomyRequestForm robotomy("robotomy");
	PresidentialPardonForm presidential("presidential");

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	bureaucrat.signForm(robotomy);
	bureaucrat.signForm(shrubbery);
	bureaucrat.signForm(presidential);
	bureaucrat.executeForm(shrubbery);
	bureaucrat.executeForm(robotomy);
	bureaucrat.executeForm(presidential);

	return (0);
}

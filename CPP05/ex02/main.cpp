#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("John", 1);
	ShrubberyCreationForm shrubbery("home");

	std::cout << shrubbery << std::endl;
	bureaucrat.signForm(shrubbery);
	bureaucrat.executeForm(shrubbery);

	return (0);
}

#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
	Intern intern;
	AForm *form1;
	AForm *form2;
	AForm *form3;

	form1 = intern.makeForm("ShrubberyCreationForm", "home");
	form2 = intern.makeForm("RobotomyRequestForm", "home");
	form3 = intern.makeForm("PresidentialPardonForm", "home");

	if (form1)
		std::cout << *form1 << std::endl;
	if (form2)
		std::cout << *form2 << std::endl;
	if (form3)
		std::cout << *form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;

	return 0;
}

#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
	Intern intern;
	AForm *form1;
	AForm *form2;
	AForm *form3;
	AForm *form4;

	form1 = intern.makeForm("ShrubberyCreationForm", "home");
	form2 = intern.makeForm("robotomy request", "home");
	form3 = intern.makeForm("Presidential Pardon Form", "home");
	form4 = intern.makeForm("Random non-existent form", "home");

	if (form1)
		std::cout << *form1 << std::endl;
	if (form2)
		std::cout << *form2 << std::endl;
	if (form3)
		std::cout << *form3 << std::endl;
	if (form4)
		std::cout << *form4 << std::endl;

	delete form1;
	delete form2;
	delete form3;
	if (form4)
		delete form4;

	return 0;
}

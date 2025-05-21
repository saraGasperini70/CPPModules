#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	*bureaucrat = new Bureaucrat("John", 1);
	Bureaucrat	*bureaucrat2 = new Bureaucrat("Bob", 9);
	Form		*form = new Form("Form1", 30, 30);
	Form		*form2 = new Form("Form2", 10, 5);
	std::cout << *bureaucrat << std::endl;
	std::cout << *bureaucrat2 << std::endl;
	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;
	try
	{
		bureaucrat->signForm(*form);
		bureaucrat2->signForm(*form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bureaucrat->executeForm(*form);
		bureaucrat2->executeForm(*form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete bureaucrat;
	delete form;
	return (0);
}

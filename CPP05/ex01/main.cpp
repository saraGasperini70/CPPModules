#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	*bureaucrat = new Bureaucrat("John", 1);
	Form		*form = new Form("Form1", 1, 1);
	std::cout << *bureaucrat << std::endl;
	std::cout << *form << std::endl;
	try
	{
		bureaucrat->incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bureaucrat->decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete bureaucrat;
	delete form;
	return (0);
}

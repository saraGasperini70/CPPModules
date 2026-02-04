# include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat("John", 1);
	Bureaucrat 	*sec_bureaucrat = new Bureaucrat("Martin", 150);
	std::cout << *bureaucrat << std::endl;
	try
	{
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << *sec_bureaucrat << std::endl;
	try
	{
		sec_bureaucrat->incrementGrade();
		std::cout << *sec_bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sec_bureaucrat->decrementGrade();
		std::cout << *sec_bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete bureaucrat;
	delete sec_bureaucrat;
	return (0);
}

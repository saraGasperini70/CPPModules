# include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat("John", 1);
	std::cout << *bureaucrat << std::endl;
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
	return (0);
}

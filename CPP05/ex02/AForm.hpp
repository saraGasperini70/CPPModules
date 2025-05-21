#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <fstream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		int const toSignGrade;
		int const toExecuteGrade;

	public:
		//Constructor/deconstructor
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &src);
		virtual ~AForm();
		//Getters/Setters
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		void setName(std::string name);
		void setIsSigned(bool isSigned);
		void setSignGrade(int signGrade);
		void setExecuteGrade(int executeGrade);
		//Member functions
		AForm &operator=(const AForm &src);
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what( void ) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what( void ) const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				const char *what( void ) const throw();
		};
		virtual void execute(Bureaucrat const &executor) const = 0;
		virtual void beSigned(Bureaucrat const &bureaucrat);
};
std::ostream	&operator<<(std::ostream &out, const AForm &src);
#endif

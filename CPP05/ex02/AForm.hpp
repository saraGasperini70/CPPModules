#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const name;
		bool isSigned;
		int const toSignGrade;
		int const toExecuteGrade;

	public:
		//Constructor/deconstructor
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(AForm &src);
		virtual ~AForm();
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
		void beSigned(Bureaucrat &bureaucrat);

		// Pure virtual function
		virtual void execute(Bureaucrat const &executor) const = 0;

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
};
std::ostream	&operator<<(std::ostream &out, const AForm &src);
#endif

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		//Constructor/deconstructor
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &src);
		~Bureaucrat();
		//Getters/Setters
		std::string getName(void) const;
		int getGrade(void) const;
		void setName(std::string name);
		void setGrade(int grade);
		//Member functions
		Bureaucrat &operator=(const Bureaucrat &src);
		void incrementGrade();
		void decrementGrade();
		void signForm(std::string formName);
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
	};
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif

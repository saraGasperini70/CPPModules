#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
	public:
		//Constructor/deconstructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();
		std::string getTarget(void) const;
		void setTarget(std::string target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		void execute(Bureaucrat const &executor) const;
};

	std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &src);
#endif

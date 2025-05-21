#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
// Ensure AForm.hpp includes the full definition of AForm and does not forward-declare it only.

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string target;
	public:
		//Constructor/deconstructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		std::string getTarget(void) const;
		void setTarget(std::string target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		void execute(Bureaucrat const &executor) const;
		//= operator
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &src);
};

	std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &src);
#endif

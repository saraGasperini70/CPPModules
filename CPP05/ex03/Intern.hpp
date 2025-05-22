#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		AForm *makeForm(std::string formName, std::string target);
		Intern &operator=(const Intern &src);
};
std::ostream &operator<<(std::ostream &out, const Intern &src);
#endif

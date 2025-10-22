#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		AForm *makeForm(std::string formName, std::string target);
		Intern &operator=(const Intern &src);
};
std::ostream &operator<<(std::ostream &out, const Intern&);
#endif

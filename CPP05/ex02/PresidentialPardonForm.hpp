#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string target;
	public:
		//Constructor/deconstructor
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		std::string getTarget(void) const;
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		void execute(Bureaucrat const &executor) const;
};
	std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &src);
#endif

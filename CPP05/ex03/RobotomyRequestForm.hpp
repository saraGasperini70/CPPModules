#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		const std::string target;
	public:
		//Constructor/deconstructor
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		std::string getTarget(void) const;
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		void execute(Bureaucrat const &executor) const;
		//= operator
		RobotomyRequestForm &operator=(RobotomyRequestForm &src);
};
std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &src);
#endif

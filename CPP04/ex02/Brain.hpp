#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		//Constructors/deconstructor
		Brain();
		Brain(Brain &src);
		~Brain();
		//Member functions
		Brain &operator=(const Brain &src);
};

#endif

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string type;
		Brain	*brain;

	public:
		//Constructor/deconstructor
		AAnimal();
		AAnimal(AAnimal &src);
		virtual ~AAnimal();

		//Getters/Setters
		std::string getType(void) const;
		void setType(std::string type);

		//Member functions
		AAnimal &operator=(const AAnimal &src);
		virtual void	makeSound(void) const = 0;
};

#endif

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain	*brain;

	public:
		//Constructor/deconstructor
		Animal();
		Animal(Animal &src);
		virtual ~Animal();

		//Getters/Setters
		std::string getType(void) const;
		void setType(std::string type);

		//Member functions
		Animal &operator=(const Animal &src);
		virtual void	makeSound(void) const;
};

#endif
